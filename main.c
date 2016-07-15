
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
	int maxsize;
	int *stk;
	int top;
};
typedef struct Stack stack;


stack init_stack();
stack push_stack(stack, int);
stack pop_stack(stack);
void print_stack(stack);
void del_stack(stack);

stack init_stack(){
	stack i;
	
	i.maxsize = 32;
	i.top = 0;
	i.stk = calloc(i.maxsize, sizeof(int));
	
	return i;
}

stack push_stack(stack pu, int n){
		
	if(pu.top == pu.maxsize){
		pu.maxsize+=32;
		int *new = calloc(pu.maxsize, sizeof(int));
		memcpy(new, pu.stk, (pu.maxsize-32)*sizeof(int));
		free(pu.stk);
		
		pu.stk = new;
	}
	
	pu.stk[pu.top] = n;
	pu.top++;
	
	return pu;
}

stack pop_stack(stack po){
	po.stk[po.top] = 0;
	po.top--;
	
	return po;
}

void print_stack(stack pr){
	int i;
	for(i = pr.maxsize; i > -1; i--){
		printf("pos:\t%d\tval:\t%d\n", i, pr.stk[i]);
	}
}

void del_stack(stack d){
	free(d.stk);
}

int main(){
	stack s = init_stack();
	
	int i = 0;
	for(i = 0; i < 35; i++){
		s = push_stack(s, i);
	}
	
	print_stack(s);
	
	for(i = 0; i < 3; i++){
		s = pop_stack(s);
	}
	
	print_stack(s);
	
	del_stack(s);
	
	return 0;
}
