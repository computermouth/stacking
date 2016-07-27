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

void print_shape(shape g_shape){
	printf("\t\t[shape start]\n");
	//printx
	int i = 0;
	printf("\t\t\tx:\t");
	for(; i < g_shape.points; i++){
		printf(" %d", g_shape.x[i]);
	}
	printf("\n");
	
	//printy
	i = 0;
	printf("\t\t\ty:\t");
	for(; i < g_shape.points; i++){
		printf(" %d", g_shape.y[i]);
	}
	printf("\n");
	
	//printpoints
	printf("\t\t\tp:\t %d\n", g_shape.points);
	
	//printcolor
	printf("\t\t\tc:\t");
	for(i = 0; i < 4; i++){
		printf(" %d", g_shape.color[i]);
	}	
	printf("\n");
	
	//printpoints
	printf("\t\t\tz:\t %d\n", g_shape.z);
	
	printf("\t\t[shape end]\n");
}

void del_shape(shape g_shape){
	free(g_shape.x);
	free(g_shape.y);
	free(g_shape.color);
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

object push_object(object g_object, shape g_shape){
		
	if(g_object.top == g_object.maxsize){
		g_object.maxsize+=32;
		shape *new = calloc(g_object.maxsize, sizeof(shape));
		memcpy(new, g_object.shp, (g_object.maxsize-32)*sizeof(shape));
		free(g_object.shp);
		
		g_object.shp = new;
	}

	g_object.top++;
	g_object.used++;
	g_object.shp[g_object.top] = g_shape;
	
	//wasteful sort
	//~ shape key;
	//~ int j;
	
	//~ for ( j = 0 ; j <= g_object.top ; j++ ){
		//~ key = g_object.shp[j];
		//~ int i = j - 1;
		//~ while ( i >= 0 && g_object.shp[i].z > key.z ) {
			//~ g_object.shp[i + 1] = g_object.shp[i];
			//~ i = i - 1;
		//~ }    
		//~ g_object.shp[i + 1] = key;
	//~ }
	
	return g_object;
}

object pop_object(object g_object){
	g_object.top--;
	
	return g_object;
}

void print_object(object g_object){
	int i;
	printf("\t[obj start]\n");
	printf("\t  ms: %d\n", g_object.maxsize);
	printf("\t  tp: %d\n", g_object.top);
	printf("\t  zz: %d\n", g_object.z);
	for(i = 0; i <= g_object.top; i++){
		print_shape(g_object.shp[i]);
	}
	printf("\t[obj end]\n");
}

void del_object(object g_object){
	free(g_object.shp);
}


stack init_stack(){
	stack i;
	
	i.maxsize = 32;
	i.used = -1;
	i.top = -1;
	i.stk = calloc(i.maxsize, sizeof(object));
	
	return i;
}

stack push_stack(stack g_stack, object g_object){
		
	if(g_stack.top == g_stack.maxsize){
		g_stack.maxsize+=32;
		object *new = calloc(g_stack.maxsize, sizeof(object));
		memcpy(new, g_stack.stk, (g_stack.maxsize-32)*sizeof(object));
		free(g_stack.stk);
		
		g_stack.stk = new;
	}
	
	g_stack.top++;
	g_stack.used++;
	g_stack.stk[g_stack.top] = g_object;
	
	//wasteful sort
	//~ object key;
	//~ int j;
	
	//~ for ( j = 0 ; j <= g_stack.top ; j++ ){
		//~ key = g_stack.stk[j];
		//~ int i = j - 1;
		//~ while ( i >= 0 && g_stack.stk[i].z > key.z ) {
			//~ g_stack.stk[i + 1] = g_stack.stk[i];
			//~ i = i - 1;
		//~ }    
		//~ g_stack.stk[i + 1] = key;
	//~ }
	
	return g_stack;
}

stack pop_stack(stack g_stack){
	g_stack.top = g_stack.top -1;
	
	return g_stack;
}

void print_stack(stack g_stack){
	int i;
	printf("[stack start]\n");
	printf("  ms: %d\n", g_stack.maxsize);
	printf("  tp: %d\n", g_stack.top);
	for(i = 0; i <= g_stack.top; i++){
		print_object(g_stack.stk[i]);
	}
	printf("[stack end]\n");
}

void del_stack(stack g_stack){
	int o;
	for(o = 0; o <= g_stack.used; o++){
		int s;
		for(s = 0; s <= g_stack.stk[o].used; s++){
			del_shape(g_stack.stk[o].shp[s]);
		}
		del_object(g_stack.stk[o]);
	}
	free(g_stack.stk);
}
