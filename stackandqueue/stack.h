#ifndef _INCLUDED_STACK_
#define _INCLUDED_STACK_
// _INCLUDED_STACK_
#include<stdint.h>
#include<assert.h>
#include<stddef.h>
#include<stddef.h>
#define MAX_DEPTH 32
typedef struct _stack_ stack;
typedef struct _stackresult_ stackresult;
struct _stack_{
	uint32_t size;
	int32_t top;
	int32_t data[MAX_DEPTH];
};
struct _stackresult_{
	int32_t data;
	uint32_t status;
};

#define STACK_OK 1
#define STACK_FULL 2
#define STACK_EMPTY 3

stack stack_new(uint32_t size);
uint32_t stack_full(stack *stk);
uint32_t stack_empty(stack *stk);
stack* stack_push(stack *stk,int32_t element,stackresult *res);
stack* stack_pop(stack *stk,stackresult *res);
stack* stack_peak(stack *stk,stackresult *res);

#endif
