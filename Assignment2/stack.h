#ifndef _INCLUDED_STACK_
#define _INCLUDED_STACK_
// _INCLUDED_STACK_
#include<stdint.h>
#include<assert.h>
#include<stddef.h>
#include<stddef.h>
#include<stdlib.h>
#define MAX_DEPTH 32
#define DATA_TYPE_USED char
typedef struct _stack_ stack;
//typedef struct _stacks_ stacks;
typedef struct _stackresult_ stackresult;
struct _stack_{
	uint32_t size;
	int32_t top;
	DATA_TYPE_USED data[MAX_DEPTH];
};
struct _stackresult_{
	DATA_TYPE_USED data;
	uint32_t status;
};
/*
struct _stacks_{
	uint32_t size;
	int32_t top;
	char32_t data[MAX_DEPTH];
};
*/
#define STACK_OK 1
#define STACK_FULL 2
#define STACK_EMPTY 3

stack stack_new(uint32_t size);
uint32_t stack_full(stack *stk);
uint32_t stack_empty(stack *stk);
stack* stack_push(stack *stk,DATA_TYPE_USED element,stackresult *res);
stack* stack_pop(stack *stk,stackresult *res);
int32_t evaluate(stack *stk,DATA_TYPE_USED exp[10],stackresult *res);
stack* postfix(stack *stk,DATA_TYPE_USED exp1[10],stackresult *res);
//stack* stack_peak(stack *stk,stackresult *res);

#endif


