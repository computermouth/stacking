
#ifndef _O_KEYWHOLES_H_
#define _O_KEYWHOLES_H_

#include "../state/state.h"
#include "../stack/stack.h"

#include "keywholes/whole.h"

struct O_whole{
	whole_01 o_whole_01;
	whole_02 o_whole_02;
	whole_03 o_whole_03;
};
typedef struct O_whole o_whole;

o_whole init_o_whole();

void del_o_whole();

object push_keywhole(state *, o_whole);

#endif
