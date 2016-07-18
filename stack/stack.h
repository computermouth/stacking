
#ifndef _STACK_H_
#define _STACK_H_

struct Shape{
	short *x;
	short *y;
	short points;
	short *color;
	short z;
};
typedef struct Shape shape;

struct Object{
	int maxsize;
	int used;
	shape *shp;
	int top;
	int z;
};
typedef struct Object object;

struct Stack{
	int maxsize;
	int used;
	object *stk;
	int top;
};
typedef struct Stack stack;

shape init_shape(short *, short *, short, short *, short);
void print_shape(shape);
void del_shape(shape);

object init_object();
object push_object(object, shape);
object pop_object(object);
void print_object(object);
void del_object(object);

stack init_stack();
stack push_stack(stack, object);
stack pop_stack(stack);
void print_stack(stack);
void del_stack(stack);

#endif
