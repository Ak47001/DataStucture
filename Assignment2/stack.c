#include<stdint.h>
#include<assert.h>
#include<stddef.h>
#include"stack.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
stack stack_new(uint32_t size)
{
	size=(size>0 && size<32)? size : MAX_DEPTH;
	stack s={size,-1,{'\0'}};
	return s;
}
stack* stack_push(stack *stk,DATA_TYPE_USED element,stackresult *res)
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

int32_t evaluate(stack *stk,DATA_TYPE_USED exp[10],stackresult *res)
{
    int i;
    for (i = 0; exp[i] != '\0';i++)
    {

		if (exp[i] == '(')

		{

			stack_push(stk,exp[i],res);

		}

		if (exp[i] == ')')

		{

			stack_pop(stk,res);

		}

	}
	return stk->top==-1;
}
stack* postfix(stack *stk,char exp1[10],stackresult*res)
{
    int i,n1,n2,n3;
    char n4,num;
    for (i = 0; exp1[i] != '\0';i++)
        {
                if(isdigit(exp1[i]))
                {
                        num =exp1[i];
                        stack_push(stk,num,res);
                }
                else
                {
                        stack_pop(stk,res);
                        n1 = res->data-'0';
                        stack_pop(stk,res);
                        n2 = res->data-'0';
                        switch(exp1[i])
                        {
                                case '+':
                                {
                                        n3 = n1 + n2;
                                        break;
                                }
                                case '-':
                                {
                                        n3 = n2 - n1;
                                        break;
                                }
                                case '*':
                                {
                                        n3 = n1 * n2;
                                        break;
                                }
                                case '/':
                                {
                                        n3 = n2 / n1;
                                        break;
                                }
                        }
                        n4=n3+'0';
                        stack_push(stk,n4,res);
                }

        }
        return stk;
}


