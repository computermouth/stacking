
#ifndef _STATE_H_
#define _STATE_H_

struct Keys{
	unsigned char esc;
	unsigned char ent;
	unsigned char w;
	unsigned char a;
	unsigned char s;
	unsigned char d;
	unsigned char up;
	unsigned char dn;
	unsigned char lt;
	unsigned char rt;
};
typedef struct Keys keys;

struct State{
	keys k;
	int keyshape_delay;
	int keywhole_stg;
	int keypurp_stg;
};
typedef struct State state;

state init_state();

#endif
