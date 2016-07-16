#include <stdio.h>
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
	
	i.z = z;
	
	return i;
}

void print_shape(shape pr){
	printf("\t\t[shape start]\n");
	//printx
	int i = 0;
	printf("\t\t\tx:\t");
	for(; i < pr.points; i++){
		printf(" %d", pr.x[i]);
	}
	printf("\n");
	
	//printy
	i = 0;
	printf("\t\t\ty:\t");
	for(; i < pr.points; i++){
		printf(" %d", pr.y[i]);
	}
	printf("\n");
	
	//printpoints
	printf("\t\t\tp:\t %d\n", pr.points);
	
	//printcolor
	printf("\t\t\tc:\t");
	for(i = 0; i < 4; i++){
		printf(" %d", pr.color[i]);
	}	
	printf("\n");
	
	//printpoints
	printf("\t\t\tz:\t %d\n", pr.z);
	
	printf("\t\t[shape end]\n");
}

void del_shape(shape ds){
	free(ds.x);
	free(ds.y);
	free(ds.color);
}

object init_object(){
	object i;
	
	i.maxsize = 32;
	i.top = -1;
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
	
	pu.top++;
	pu.shp[pu.top] = s;
	
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
	int i;
	printf("\t[obj start]\n");
	printf("\t  ms: %d\n", pr.maxsize);
	printf("\t  tp: %d\n", pr.top);
	printf("\t  zz: %d\n", pr.z);
	for(i = 0; i <= pr.top; i++){
		print_shape(pr.shp[i]);
	}
	printf("\t[obj end]\n");
}

void del_object(object d){
	free(d.shp);
}


stack init_stack(){
	stack i;
	
	i.maxsize = 32;
	i.top = -1;
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
	
	pu.top++;
	pu.stk[pu.top] = n;
	
	return pu;
}

stack pop_stack(stack po){
	po.top--;
	
	return po;
}

void print_stack(stack pr){
	int i;
	printf("[stack start]\n");
	printf("  ms: %d\n", pr.maxsize);
	printf("  tp: %d\n", pr.top);
	for(i = 0; i <= pr.top; i++){
		print_object(pr.stk[i]);
	}
	printf("[stack end]\n");
}

void del_stack(stack d){
	free(d.stk);
}
