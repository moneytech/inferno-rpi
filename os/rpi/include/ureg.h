typedef struct Ureg {
	uint	r0;
	uint	r1;
	uint	r2;
	uint	r3;
	uint	r4;
	uint	r5;
	uint	r6;
	uint	r7;
	uint	r8;
	uint	r9;
	uint	r10;
	uint	r11;
	uint	r12; /* sb */
	union {
		uint	r13;
		uint	sp;
	};
	union {
		uint	r14;
		uint	link;
	};
	uint	type; /* of exception */
	uint	psr;
	uint	pc; /* interrupted addr */
} Ureg;
