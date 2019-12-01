
#include<stdint.h>
#include<assert.h>
#include<stddef.h>
#include"stack.h"
stack stack_new(uint32_t size)
{
	size=(size>0 && size<32)? size : MAX_DEPTH;
	stack s={size,-1,{0}};
	return s;
}
stack* stack_push(stack *stk,int32_t element,stackresult *res)
{
	assert(stk!=NULL);
	if(stk->top+1<stk->size){
		stk->data[++stk->top]=element;
		res->data=element;
		res->status=STACK_OK;

	}
	else
	{
		res->status=STACK_FULL;
	}
	assert((res->status==STACK_OK)||((stk->top+1)==stk->size));

	return stk;

}
uint32_t stack_full(stack *stk)
{
    assert(stk!=NULL);
    return(stk->top+1==stk->size);
}
uint32_t stack_empty(stack *stk)
{
    assert(stk!=NULL);
    return(stk->top==-1);
}
stack* stack_peak(stack *stk,stackresult *res)
{
	assert(stk!=NULL);
	if(stk->top>-1)
	{
		res->data=stk->data[stk->top];
		res->status=STACK_OK;
	}
	else
	{
		res->status=STACK_EMPTY;
	}
	return stk;
}
stack* stack_pop(stack *stk,stackresult *res)
{
	assert(stk!=NULL);
	if(stk->top>=0){
		res->data=stk->data[stk->top];
		--stk->top;
		res->status=STACK_OK;

	}
	else
	{
		res->status=STACK_EMPTY;
	}
	assert((res->status==STACK_OK) || (stk->top==-1));
	return stk;

}
