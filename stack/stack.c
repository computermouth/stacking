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
	i.used = -1;
	i.top = -1;
	i.shp = calloc(i.maxsize, sizeof(shape));
	i.z = 0;
	
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
	pu.used++;
	pu.shp[pu.top] = s;
	
	//wasteful sort
	shape key;
	int j;
	
	for ( j = 0 ; j <= pu.top ; j++ ){
		key = pu.shp[j];
		int i = j - 1;
		while ( i >= 0 && pu.shp[i].z > key.z ) {
			pu.shp[i + 1] = pu.shp[i];
			i = i - 1;
		}    
		pu.shp[i + 1] = key;
	}
	
	return pu;
}

object pop_object(object po){
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
	i.used = -1;
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
	pu.used++;
	pu.stk[pu.top] = n;
	
	//wasteful sort
	object key;
	int j;
	
	for ( j = 0 ; j <= pu.top ; j++ ){
		key = pu.stk[j];
		int i = j - 1;
		while ( i >= 0 && pu.stk[i].z > key.z ) {
			pu.stk[i + 1] = pu.stk[i];
			i = i - 1;
		}    
		pu.stk[i + 1] = key;
	}
	
	return pu;
}

stack pop_stack(stack po){
	po.top = po.top -1;
	
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
	int o;
	for(o = 0; o <= d.used; o++){
		int s;
		for(s = 0; s <= d.stk[o].used; s++){
			del_shape(d.stk[o].shp[s]);
		}
		del_object(d.stk[o]);
	}
	free(d.stk);
}
