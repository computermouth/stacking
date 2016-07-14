
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
	int maxsize;
	int *stk;
	int top;
};
typedef struct Stack stack;

stack init_stack(){
	stack i;
	
	i.maxsize = 32;
	i.top = 0;
	i.stk = calloc(i.maxsize, sizeof(int));
	
	return i;
}

stack push_stack(stack pu, int n){
	
	if(pu.top == pu.maxsize){
		int *new = calloc(pu.maxsize+32, sizeof(int));
		memcpy(pu.stk, new, sizeof(int));
		free(pu.stk);
		
		pu.stk = new;
	}
	
	pu.top++;
	pu.stk[pu.top] = n;
	
	return pu;
}

void del_stack(stack d){
	free(d.stk);
}

int main(){
	stack s = init_stack();
	
	while(s.top < 65){
		printf("pre-stack top: %d\n", s.stk[s.top]);
		
		s = push_stack(s, s.top);
		
		printf("post-stack top: %d\n", s.stk[s.top]);
	}
	
	del_stack(s);
	
	return 0;
}
