int	addfile(File*);
void	addfnptrs(Decl*, int);
void	addiface(Decl*, Decl*);
void	addinclude(char*);
char	*addrprint(char*, char*, int, Addr*);
Typelist	*addtype(Type*, Typelist*);
Node	*adtdecl(Decl *ids, Node *fields);
void	adtdecled(Node *n);
void	adtdefd(Type*);
Decl	*adtmeths(Type*);
void	adtstub(Decl*);
long	align(long, int);
void	*allocmem(ulong);
void	altcheck(Node *an, Type *ret);
void	altcom(Node*);
Inst	*andand(Node*, int, Inst*);
Decl	*appdecls(Decl*, Decl*);
int	argcompat(Node*, Decl*, Node*);
void	arraycom(Node*, Node*);
void	arraydefault(Node*, Node*);
Type	*arrowtype(Type*, Decl*);
void	asmdesc(Desc*);
void	asmentry(Decl*);
void	asmexc(Except*);
void	asminitializer(long, Node*);
void	asminst(Inst*);
void	asmldt(long, Decl*);
void	asmmod(Decl*);
void	asmpath(void);
void	asmstring(long, Sym*);
void	asmvar(long, Decl*);
int	assignindices(Node*);
void	bccom(Node*, Inst**);
Inst	*bcom(Node*, int, Inst*);
void	bindnames(Node*);
void	bindtypes(Type *t);
Ok	callcast(Node*, int, int);
void	callcom(Src*, int, Node*, Node*);
Type*	calltype(Type*, Node*, Type*);
double	canontod(ulong v[2]);
void	casecheck(Node *cn, Type *ret);
int	casecmp(Type*, Node*, Node*);
void	casecom(Node*);
Node	*caselist(Node*, Node*);
void	casesort(Type*, Label*, Label*, int, int);
Case	*checklabels(Node *inits, Type *ctype, int nlab, char *title);
void	checkrefs(Decl*);
Node	*checkused(Node*);
int	circlval(Node*, Node*);
void	concheck(Node *n, int isglobal);
Node	*condecl(Decl*, Node*);
void	condecled(Node *n);
void	constub(Decl*);
Type	*copytypeids(Type*);
char	*ctprint(char*, char*, Type*);
int	ctypeconv(Fmt*);
Line	curline(void);
Decl	*curscope(void);
int	cycarc(Type*, Type*);
void	cycfield(Type*, Decl*);
void	cycsizetype(Type*);
void	cyctype(Type*);
int	dasdecl(Node *n);
void	declaserr(Node*);
int	declasinfer(Node*, Type*);
int	declconv(Fmt*);
Decl	*declsort(Decl*);
void	declstart(void);
void	decltozero(Node *n);
void	deldecl(Decl*);
int	dequal(Decl*, Decl*, int);
long	descmap(Decl*, uchar*, long);
void	disaddr(int, Addr*);
void	disbcon(long);
void	discon(long);
void	disdata(int, long);
void	disdesc(Desc*);
void	disentry(Decl*);
void	disexc(Except*);
void	disinst(Inst*);
void	disldt(long, Decl*);
void	dismod(Decl*);
void	dispath(void);
void	disvar(long, Decl*);
void	disword(long);
int	dotconv(Fmt*);
char	*dotprint(char*, char*, Decl*, int);
Type	*dottype(Type*, Decl*);
void	dtocanon(double, ulong[2]);
Decl	*dupdecl(Decl*);
Decl *dupdecls(Decl*);
Node	*dupn(int, Src*, Node*);
Node	*eacom(Node*, Node*, Node*);
Ok	echeck(Node *n, int typeok, int isglobal, Node* par);
Node	*ecom(Src*, Node*, Node*);
Node	*efold(Node *n);
Node	*elemsort(Node*);
void	emit(Decl*);
Decl	*encpolys(Decl*);
Sym	*enter(char*, int);
Desc	*enterdesc(uchar*, long, long);
Sym	*enterstring(char*, int);
char	*eprint(char*, char*, Node*);
char	*eprintlist(char*, char*, Node*, char*);
void	error(Line, char*, ...);
#pragma	varargck	argpos	error	2
int	etconv(Fmt*);
Node	*etolist(Node*);
void	excheck(Node *n, int isglobal);
void	exccheck(Node *cn, Type *ret);
void	excom(Node*);
Node	*exdecl(Decl*, Decl*);
void	exdecled(Node *n);
Type	*expandtype(Type*, Type*, Decl*, Tpair**);
Type	*expandtypes(Type*, Decl*);
int	expconv(Fmt*);
Type	*exptotype(Node*);
void	fatal(char*, ...);
#pragma	varargck	argpos	fatal	1
void	fielddecled(Node *n);
Node	*fielddecl(int store, Decl *ids);
int	findlab(Type *ty, Node *v, Label *labs, int nlab);
int	fixop(int, Type*, Type*, Type*, int*, int*);
Fline	fline(int);
void	fmtcheck(Node*, Node*, Node*);
void	fncheck(Decl *d);
Decl	*fnchk(Node *n);
void	fncom(Decl*);
Node	*fndecl(Node *n, Type *t, Node *body);
void	fndecled(Node *n);
Decl*	fnlookup(Sym*, Type*, Node**);
Node	*fold(Node*);
void	foldbranch(Inst*);
Node	*foldc(Node*);
Node	*foldcast(Node*, Node*);
Node	*foldcasti(Node*, Node*);
Node	*foldr(Node*);
Node	*foldvc(Node*);
void	gbind(Node *n);
int	gcheck(Node*, Decl**, int);
void	gdasdecl(Node *n);
void	gdecl(Node *n);
Addr	genaddr(Node*);
Inst	*genbra(Src*, int, Node*, Node*);
Inst	*genchan(Src*, Node*, Type*, Node*);
Desc	*gendesc(Decl*, long, Decl*);
Inst	*genfixcastop(Src*, int, Node*, Node*);
Inst	*genmove(Src*, int, Type*, Node*, Node*);
Inst	*genop(Src*, int, Node*, Node*, Node*);
Inst	*genrawop(Src*, int, Node*, Node*, Node*);
void	genstart(void);
long	getpc(Inst*);
int	gfltconv(Fmt*);
Decl	*globalBconst(Node*);
Node	*globalas(Node*, Node*, int);
Decl	*globalbconst(Node*);
Decl	*globalconst(Node*);
Decl	*globalfconst(Node*);
Decl	*globalsconst(Node*);
void	gsort(Node*);
int	hasasgns(Node*);
int	hascall(Node*);
Node	*hascomm(Node*);
int	hasside(Node*, int);
long	idindices(Decl*);
long	idoffsets(Decl*, long, int);
Type	*idtype(Type*);
void	importcheck(Node *n, int isglobal);
void	importchk(Node*);
Node	*importdecl(Node *m, Decl *ids);
void	importdecled(Node *n);
void	includef(Sym*);
Node	*indsascom(Src*, Node*, Node*);
int	initable(Node*, Node*, int);
int	inloop(void);
void	installids(int store, Decl *ids);
int	instconv(Fmt*);
Type	*insttype(Type*, Decl*, Tpair**);
Type	*internaltype(Type*);
int	isimpmod(Sym*);
int	islval(Node*);
int	ispoly(Decl*);
int	ispolyadt(Type*);
int	istuple(Node*);
void	joiniface(Type*, Type*);
void	lexinit(void);
void	lexstart(char*);
int	lineconv(Fmt*);
int	local(Decl*);
Decl	*lookdot(Decl*, Sym*);
Decl *lookup(Sym*);
int	mapconv(Fmt*);
int	marklval(Node*);
int	mathchk(Node*, int);
void	mergepolydecs(Type*);
Type	*mkadtcon(Type*);
Type	*mkadtpickcon(Type*, Type*);
Type	*mkarrowtype(Line*, Line*, Type*, Sym*);
Node	*mkbin(int, Node*, Node*);
Node	*mkconst(Src*, Long);
Decl	*mkdecl(Src*, int, Type*);
Node	*mkdeclname(Src*, Decl*);
Desc	*mkdesc(long, Decl*);
Type	*mkdottype(Line*, Line*, Type*, Sym*);
Type	*mkexbasetype(Type*);
Type	*mkextuptype(Type*);
Type	*mkextype(Type*);
File	*mkfile(char*, int, int, int, char*, int, int);
Decl	*mkids(Src*, Sym*, Type*, Decl*);
Type	*mkidtype(Src*, Sym*);
Type	*mkiface(Decl*);
Inst	*mkinst(void);
Type *mkinsttype(Src*, Type*, Typelist*);
Node	*mkname(Src*, Sym*);
Node	*mknil(Src*);
Node	*mkn(int, Node*, Node*);
Node	*mkrconst(Src*, Real);
Node	*mksconst(Src*, Sym*);
Node	*mkscope(Node *body);
Type	*mktalt(Case*);
Desc	*mktdesc(Type*);
Node	*mktn(Type*);
Type	*mktype(Line*, Line*, int, Type*, Decl*);
Node	*mkunary(int, Node*);
Type	*mkvarargs(Node*, Node*);
Teq	*modclass(void);
void	modcode(Decl*);
void	modcom(Decl*);
void	moddataref(void);
Node	*moddecl(Decl *ids, Node *fields);
void	moddecled(Node *n);
Decl	*modglobals(Decl*, Decl*);
Decl	*modimp(Dlist*, Decl*);
void	modrefable(Type*);
void	modresolve(void);
void	modstub(Decl*);
void	modtab(Decl*);
Decl	*module(Decl*);
int	mustzero(Decl *);
int	mpatof(char*, double*);
Decl	*namedot(Decl*, Sym*);
Decl	*namesort(Decl*);
void	narrowmods(void);
void	nerror(Node*, char*, ...);
#pragma	varargck	argpos	nerror	2
int	nested(void);
Inst	*nextinst(void);
int	nodeconv(Fmt*);
int	nodes(Node*);
char	*nprint(char*, char*, Node*, int);
void	nwarn(Node*, char*, ...);
#pragma	varargck	argpos	nwarn	2
int	occurs(Decl*, Node*);
int	opconv(Fmt*);
void	optabinit(void);
void	optim(Inst*, Decl*);
Inst	*oror(Node*, int, Inst*);
Decl	*outerpolys(Node*);
Node	*passfns(Src*, Decl*, Node*, Node*, Type*, Tpair*);
Node	*passimplicit(Node*, Node*);
void	patch(Inst*, Inst*);
void	pickcheck(Node*, Type*);
int	pickdecled(Node *n);
Decl	*pickdefd(Type*, Decl*);
void	pickdupcom(Src*, Node*, Node*);
Decl*	polydecl(Decl*);
int	polyequal(Decl*, Decl*);
void	popblock(void);
Decl	*popids(Decl*);
void	popscopes(void);
Decl	*popscope(void);
void	printdecls(Decl*);
int	pushblock(void);
void	pushlabel(Node*);
void	pushscope(Node *, int);
void	raisescheck(Type*);
int	raisescompat(Node*, Node*);
void	reach(Inst*);
void	*reallocmem(void*, ulong);
void	recvacom(Src*, Node*, Node*);
void	redecl(Decl *d);
void	reftype(Type*);
void	repushblock(int);
void	repushids(Decl*);
void	resizetype(Type*);
long	resolvedesc(Decl*, long, Decl*);
Decl* resolveldts(Decl*, Decl**);
int	resolvemod(Decl*);
long	resolvepcs(Inst*);
Node	*retalloc(Node*, Node*);
Decl	*revids(Decl*);
Node	*rewrite(Node *n);
Node	*rewritecomm(Node*, Node*, Node*, Node*);
Inst	*rewritedestreg(Inst*, int, int);
Inst	*rewritesrcreg(Inst*, int, int, int);
void	rmfnptrs(Decl*);
Node	*rotater(Node*);
double	rpow(double, int);
int	sameaddr(Node*, Node*);
int	sametree(Node*, Node*);
void	sblfiles(void);
void	sblfn(Decl**, int);
void	sblinst(Inst*, long);
void	sblmod(Decl*);
void	sblty(Decl**, int);
void	sblvar(Decl*);
double	scale(Type*);
double	scale2(Type*, Type*);
Node*	scheck(Node*, Type*, int);
void	scom(Node*);
char	*secpy(char*, char*, char*);
char	*seprint(char*, char*, char*, ...);
#pragma	varargck	argpos	seprint	3
void	shareloc(Decl*);
int	shiftchk(Node*);
ulong	sign(Decl*);
Node	*simplify(Node*);
Szal	sizeids(Decl*, long);
void	sizetype(Type*);
Node	*slicelcom(Src*, Node*, Node*);
int	specific(Type*);
int	srcconv(Fmt*);
char*	srcpath(char*, int);
int	storeconv(Fmt*);
char	*stprint(char*, char*, Type*);
Sym	*stringcat(Sym*, Sym*);
char	*stringpr(char*, char*, Sym*);
Long	strtoi(char*, int);
int	stypeconv(Fmt*);
Node	*sumark(Node*);
int	symcmp(Sym*, Sym*);
Node	*tacquire(Node*);
Ok	tagcast(Node*, Node*, Node*, Decl*, int, int);
Node	*talloc(Node*, Type*, Node*);
int	tcompat(Type*, Type*, int);
void tcycle(Type*);
Decl	*tdecls(void);
long	tdescmap(Type*, uchar*, long);
void	teqclass(Type*);
int	tequal(Type*, Type*);
void	tfree(Node*);
void	tfreelater(Node*);
void	tfreenow(void);
void	tinit(void);
int	tmustzero(Type *);
Type	*toptype(Src*, Type*);
Type	*topvartype(Type *t, Decl *id, int tyok, int polyok);
Type*	tparent(Type*, Type*);
char	*tprint(char*, char*, Type*);
void	translate(char*, char*, char*);
void	trelease(Node*);
int	tunify(Type*, Type*, Tpair**);
int	tupaliased(Node*, Node*);
int	tupsaliased(Node*, Node*);
void	tupcom(Node*, Node*);
void	tuplcom(Node*, Node*);
void	tuplrcom(Node*, Node*);
Decl	*tuplefields(Node*);
void	typebuiltin(Decl*, Type*);
Decl	*typecheck(int);
int	typeconv(Fmt*);
Node	*typedecl(Decl *ids, Type *t);
void	typedecled(Node *n);
Decl	*typeids(Decl*, Type*);
void	typeinit(void);
void	typestart(void);
Decl	*undefed(Src *src, Sym *s);
Desc	*usedesc(Desc*);
void	usedty(Type*);
Type	*usetype(Type*);
Type	*validtype(Type*, Decl*);
int	valistype(Node*);
Type	*valtmap(Type*, Tpair*);
void	varcheck(Node *n, int isglobal);
int	varcom(Decl*);
Node	*vardecl(Decl*, Type*);
void	vardecled(Node *n);
Node	*varinit(Decl*, Node*);
Decl	*varlistdecl(Decl*, Node*);
Decl	*vars(Decl*);
int	vcom(Decl*);
Type	*verifytypes(Type*, Decl*, Decl*);
void	warn(Line, char*, ...);
#pragma	varargck	argpos	warn	2
void	yyerror(char*, ...);
#pragma	varargck	argpos	yyerror	1
int	yylex(void);
int	yyparse(void);
void	zcom(Node *, Node**);
void zcom0(Decl *, Node**);
void zcom1(Node *, Node**);
