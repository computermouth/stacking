
#include <stdlib.h>
#include <string.h>

#include "stack.h"

shape init_shape(short *x, short *y, short points, short *color, short z){
	shape i;
	
	i.x = calloc(points, sizeof(short));
	memcpy(i.x, x, points*sizeof(short));
	
	i.y = calloc(points, sizeof(short));
	memcpy(i.y, y, points*sizeof(short));
	
	i.points = points;
	
	i.color = calloc(4, sizeof(short));
	memcpy(i.color, color, 4*sizeof(short));
	
	return i;
}

object init_object(){
	object i;
	
	i.maxsize = 32;
	i.top = 0;
	i.shp = calloc(i.maxsize, sizeof(shape));
	
	return i;
}

object push_object(object pu, shape s){
		
	if(pu.top == pu.maxsize){
		pu.maxsize+=32;
		shape *new = calloc(pu.maxsize, sizeof(shape));
		memcpy(new, pu.shp, (pu.maxsize-32)*sizeof(shape));
		free(pu.shp);
		
		pu.shp = new;
	}
	
	free(s.x);
	free(s.y);
	free(s.color);
	
	pu.shp[pu.top] = s;
	pu.top++;
	
	return pu;
}

object pop_object(object po){
	free(po.shp[po.top].x);
	free(po.shp[po.top].y);
	free(po.shp[po.top].color);
	po.top--;
	
	return po;
}

void print_object(object pr){
	//~ int i;
	//~ for(i = pr.maxsize; i > -1; i--){
		//~ printf("pos:\t%d\tval:\t%d\n", i, pr.shp[i].it);
	//~ }
}

void del_object(object d){
	free(d.shp);
}


stack init_stack(){
	stack i;
	
	i.maxsize = 32;
	i.top = 0;
	i.stk = calloc(i.maxsize, sizeof(object));
	
	return i;
}

stack push_stack(stack pu, object n){
		
	if(pu.top == pu.maxsize){
		pu.maxsize+=32;
		object *new = calloc(pu.maxsize, sizeof(object));
		memcpy(new, pu.stk, (pu.maxsize-32)*sizeof(object));
		free(pu.stk);
		
		pu.stk = new;
	}
	
	pu.stk[pu.top] = n;
	pu.top++;
	
	return pu;
}

stack pop_stack(stack po){
	po.top--;
	
	return po;
}

void print_stack(stack pr){
	//~ int i;
	//~ for(i = pr.maxsize; i > -1; i--){
		//~ printf("pos:\t%d\tval:\t%d\n", i, pr.stk[i].it);
	//~ }
}

void del_stack(stack d){
	free(d.stk);
}
