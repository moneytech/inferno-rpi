#include "rc.h"

char	*globname;
Word	*globv;

int	matchfn(char *s, char *p);
int	globsize(char *p);

/*
 * delete all the GLOB marks from s, in place
 */
void
deglob(char *s)
{
	char *t=s;
	do{
		if(*t==GLOB) t++;
		*s++=*t;
	}while(*t++);
}

int
globcmp(void *s, void *t)
{
	return strcmp(*(char**)s, *(char**)t);
}

void
globsort(Word *left, Word *right)
{
	char **list;
	Word *a;
	int n=0;
	for(a=left;a!=right;a=a->next) n++;
	list=(char **)malloc(n*sizeof(char *));
	for(a=left,n=0;a!=right;a=a->next,n++) list[n]=a->word;
	qsort((void*)list, (size_t)n, sizeof(char*), globcmp);
	for(a=left,n=0;a!=right;a=a->next,n++) a->word=list[n];
	free(list);
}

/*
 * Push names prefixed by globname and suffixed by a match of p onto the astack.
 * namep points to the end of the prefix in globname.
 */
void
globdir(char *p, char *namep)
{
	char *t, *q, *newp;
	Direntry *dp, *dq;
	Dir *dir;

	/* scan the pattern looking for a component with a metacharacter in it */
	if(*p=='\0'){
		globv=newword(globname, globv);
		return;
	}
	t=namep;
	newp=p;
	while(*newp){
		if(*newp==GLOB)
			break;
		*t=*newp++;
		if(*t++=='/'){
			namep=t;
			p=newp;
		}
	}
	/* If we ran out of pattern, append the name if accessible */
	if(*newp=='\0'){
		*t='\0';
		if(access(globname, 0)==0)
			globv=newword(globname, globv);
		return;
	}
	/* read the directory and recur for any entry that matches */
	*namep='\0';
	t = globname;
	if(*t == 0)
		t = ".";
	q = strdup(t);
	if (q[strlen(q)-1] == '/')
		q[strlen(q)-1] = 0;
	if((dir=dirstat(q)) == nil || !(dir->mode&0x80000000)){
		free(dir);
		return;
	}
	free(dir);
	dq = readdirect(q);
	if(dq == 0){
		fprint(2, "could not open %s: %r\n", q);
		return;
	}
	while(*newp!='/' && *newp!='\0')
		newp++;
	for(dp = dq;dp->name; dp++){
		strcpy(namep, dp->name);
		if(matchfn(namep, p))
			globdir(newp, namep+strlen(namep));
		free(dp->name);
	}
	free(dq);
}

/*
 * Push all file names matched by p on the current thread's stack.
 * If there are no matches, the list consists of p.
 */
void
glob(char *p)
{
	Word *svglobv=globv;
	int globlen=globsize(p);

	if(globlen == 0){
		deglob(p);
		globv=newword(p, globv);
		return;
	}
	globname=malloc(globlen);
	globname[0]='\0';
	globdir(p, globname);
	free(globname);
	if(svglobv==globv){
		deglob(p);
		globv=newword(p, globv);
	}
	else
		globsort(globv, svglobv);
}


/*
 * Do p and q point at equal utf codes
 */
int
equtf(char *p, char *q)
{
	if(*p!=*q)
		return 0;
	if(twobyte(*p)) return p[1]==q[1];
	if(threebyte(*p)){
		if(p[1]!=q[1]) return 0;
		if(p[1]=='\0') return 1;	/* broken code at end of string! */
		return p[2]==q[2];
	}
	return 1;
}

/*
 * Return a pointer to the next utf code in the string,
 * not jumping past nuls in broken utf codes!
 */
char *
nextutf(char *p)
{
	if(twobyte(*p))
		return p[1]=='\0'?p+1:p+2;
	if(threebyte(*p))
		return p[1]=='\0'?p+1:p[2]=='\0'?p+2:p+3;
	return p+1;
}

/*
 * Convert the utf code at *p to a unicode value
 */
int
unicode(char *p)
{
	int u=*p&0xff;
	if(twobyte(u))
		return ((u&0x1f)<<6)|(p[1]&0x3f);
	if(threebyte(u))
		return (u<<12)|((p[1]&0x3f)<<6)|(p[2]&0x3f);
	return u;
}

/*
 * Does the string s match the pattern p
 * . and .. are only matched by patterns starting with .
 * * matches any sequence of characters
 * ? matches any single character
 * [...] matches the enclosed list of characters
 */
int
matchfn(char *s, char *p)
{
	if(s[0]=='.' && (s[1]=='\0' || s[1]=='.' && s[2]=='\0') && p[0]!='.')
		return 0;
	return match(s, p, '/');
}

int
match(char *s, char *p, int stop)
{
	int compl, hit, lo, hi, t, c;

	for(;*p!=stop && *p!='\0';s=nextutf(s),p=nextutf(p)) {
		if(*p!=GLOB){
			if(!equtf(p, s)) return 0;
		}
		else switch(*++p){
		case GLOB:
			if(*s!=GLOB) return 0;
			break;
		case '*':
			for(;;){
				if(match(s, nextutf(p), stop)) return 1;
				if(!*s) break;
				s=nextutf(s);
			}
			return 0;
		case '?':
			if(*s=='\0') return 0;
			break;
		case '[':
			if(*s=='\0') return 0;
			c=unicode(s);
			p++;
			compl=*p=='~';
			if(compl) p++;
			hit=0;
			while(*p!=']'){
				if(*p=='\0') return 0;		/* syntax error */
				lo=unicode(p);
				p=nextutf(p);
				if(*p!='-') hi=lo;
				else{
					p++;
					if(*p=='\0') return 0;	/* syntax error */
					hi=unicode(p);
					p=nextutf(p);
					if(hi<lo){ t=lo; lo=hi; hi=t; }
				}
				if(lo<=c && c<=hi) hit=1;
			}
			if(compl) hit=!hit;
			if(!hit) return 0;
			break;
		}
	}
	return *s=='\0';
}

void
globlist1(Word *gl)
{
	if(gl){
		globlist1(gl->next);
		glob(gl->word);
	}
}

void
globlist(void)
{
	Word *a;

	globv=0;
	globlist1(runq->argv->words);
	poplist();
	pushlist();
	if(globv){
		for(a=globv;a->next;a=a->next);
		a->next=runq->argv->words;
		runq->argv->words=globv;
	}
}

#define	NDIR	128
int
globsize(char *p)
{
	ulong isglob=0, globlen=NDIR+1;

	for(;*p;p++){
		if(*p==GLOB){
			p++;
			if(*p!=GLOB) isglob++;
			globlen+=*p=='*'?NDIR:1;
		}
		else
			globlen++;
	}
	return isglob?globlen:0;
}
