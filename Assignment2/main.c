#include<assert.h>
#include<stdint.h>
#include<stdlib.h>
#include"stack.h"
void test_stackque()
{
	stack s=stack_new(10);
	stack *stk=&s;
	stackresult res;
	/*
	stk=stack_push(stk,10,&res);
	stk=stack_push(stk,30,&res);
	stk=stack_push(stk,500,&res);
	stk=stack_push(stk,70,&res);
	assert(res.data=70);
	*/
	DATA_TYPE_USED exp[10]="(a+b)";
	DATA_TYPE_USED exp1[10]="245+*";
	assert(evaluate(stk,exp,&res)==1);
	stk=postfix(stk,exp1,&res);
	assert(res.data-'0'==18);

}
int main()
{
	test_stackque();
	return 0;
}
