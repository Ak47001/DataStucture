#include<assert.h>
#include<stdint.h>
#include"stack.h"
#include"queue.h"
void constant_memory()
{
    queue k= queue_new(10);
    queue *q=&k;
    queueresult qres;
    q=queue_add(q,55,&qres);
    q=queue_add(q,60,&qres);
    q=queue_add(q,75,&qres);
    q=queue_add(q,90,&qres);
    stack l = stack_new(10);
    stack *s=&l;
    stackresult sres;
    assert(q->count==4);
    int n1=1;
    int n2=q->count;

    while(n1<=n2)
    {
    int n3=1;
    while(n3<q->count)
    {
        q = queue_delete(q,&qres);
        q = queue_add(q,qres.data,&qres);
        n3++;
    }
        q = queue_delete(q,&qres);
        s = stack_push(s,qres.data,&sres);

        n1++;
}
    s = stack_peak(s,&sres);
    assert(sres.data==55);
}

void stackTOqueue()
{
    stack k = stack_new(10);
    stack *s=&k;
    stackresult sres;
    s = stack_push(s,93,&sres);
    s = stack_push(s,53,&sres);
    s = stack_push(s,73,&sres);
    s = stack_push(s,83,&sres);
    queue l= queue_new(10);
    queue *q=&l;
    queueresult qres;
    int element = 53;
    int count = 0;
    int i=0;
    while(i<=s->top+1)
    {
        s = stack_peak(s,&sres);
        if(sres.data==element)
        {
            break;
        }
        else
        {
            s = stack_pop(s,&sres);
            q = queue_add(q,sres.data,&qres);
            count++;
        }
        i++;
    }

    int n1,n2;
    n2=n1=count;
    while(count!=0)
    {
        q= queue_delete(q,&qres);
        s= stack_push(s,qres.data,&sres);
        count--;
    }
    s = stack_peak(s,&sres);
    assert(sres.data==73);

    while(n2!=0)
    {
        s=stack_pop(s,&sres);
        q=queue_add(q,sres.data,&qres);
        n2--;
    }

    s = stack_peak(s,&sres);
    assert(sres.data==53);


    while(n1!=0)
    {
        q= queue_delete(q,&qres);
        s= stack_push(s,qres.data,&sres);
        n1--;
    }

    s = stack_peak(s,&sres);
    assert(sres.data==83);

}

stack* deleteQueue(stack *s1,stack *s2,stackresult sres1,stackresult sres2)
{
	while(s1->top>-1)
	{
	s1 = stack_pop(s1,&sres1);
	int32_t element;
	element = sres1.data;
	s2 = stack_push(s2,element,&sres2);
	}
	s2 = stack_pop(s2,&sres2);
	return s2;
}


void queueUsingStacks()
{
	stack k = stack_new(10);
	stack *s1=&k;
	stackresult sres1;

	s1 = stack_push(s1,10,&sres1);
	s1 = stack_push(s1,20,&sres1);
	s1 = stack_push(s1,50,&sres1);

	stack stk2 = stack_new(10);
	stack *s2=&stk2;
	stackresult sres2;


	s2 = deleteQueue(s1,s2,sres1,sres2);
	s1 = stack_peak(s1,&sres1);
	assert(s1->top==-1);

	s2 = stack_peak(s2,&sres2);
	assert(sres2.data==20);

}

void transfer(stack *S,stack *T)
{
		stackresult sres;
		stackresult tres;

		S = stack_push(S,69,&sres);
		S = stack_push(S,79,&sres);
		S = stack_push(S,89,&sres);
		S = stack_push(S,99,&sres);

		S = stack_peak(S,&sres);
		assert(sres.data == 99);

		while(S->top>-1)
		{
		S = stack_pop(S,&sres);
		int32_t element = sres.data;
		T = stack_push(T,element,&tres);
		}

		T = stack_peak(T,&tres);
		assert(tres.data==69);

}


void reverseElement(stack *S,stack *T)
{
	stackresult sres;
    stackresult tres;

    S = stack_push(S,69,&sres);
    S = stack_push(S,79,&sres);
    S = stack_push(S,89,&sres);
    S = stack_push(S,99,&sres);

    S = stack_peak(S,&sres);
    assert(sres.data == 99);

    while(S->top>-1)
    {
        S = stack_pop(S,&sres);
        int32_t element = sres.data;
		T = stack_push(T,element,&tres);
    }

    T = stack_peak(T,&tres);
    assert(tres.data==69);

    while(T->top>-1)
    {
		T = stack_pop(T,&tres);
		int32_t revElement = tres.data;
		S = stack_push(S,revElement,&sres);
    }

		S = stack_peak(S,&sres);
		assert(sres.data == 99);
}

void CheckStackFull()
{
		stack stk = stack_new(3);
		stack *S=&stk;
		stackresult res;

		S = stack_push(S,20,&res);
		S = stack_push(S,30,&res);
		S = stack_push(S,40,&res);
		S = stack_push(S,50,&res);
		assert(res.status==2);

}

void TwoTemporaryStacks()
{
	stack k = stack_new(10);
	stack *S=&k;
	stackresult res;

	S = stack_push(S,33,&res);
	S = stack_push(S,22,&res);
	S = stack_push(S,11,&res);
	S = stack_push(S,55,&res);

	stack stk1 = stack_new(10);
	stack *temp1=&stk1;
	stackresult Tres1;

	stack stk2 = stack_new(10);
	stack *temp2=&stk2;
	stackresult Tres2;

	while(S->top>-1)
	{
        S = stack_pop(S,&res);
        int32_t element = res.data;
        temp1 = stack_push(temp1,element,&Tres1);
        temp2 = stack_push(temp2,element,&Tres2);
	}

	temp1 = stack_peak(temp1,&Tres1);
	assert(Tres1.data==33);
	temp2 = stack_peak(temp2,&Tres2);
	assert(Tres2.data==33);
}



int main()

{
/*1. Design a stack using a single queue as an instance variable,
and only constant additional local memory within the method bodies.*/
    constant_memory();

/*2.Suppose you have a stack S containing n elements and a queue Q that is initially empty.
Write function that use Q to scan S to see if it contains a certain element x, with the additional
constraint that your algorithm must return the elements back to S in their original order. You
may use S, Q and a constant number of other variables.*/
    stackTOqueue();

//3.Design a queue using two stacks as instance variables, such that all queue operations execute in amortized O(1) time.
    queueUsingStacks();

/*4. Implement a function with signature transfer(S,T) that transfers all elements from Stack S onto
Stack T, so that that elements that starts at the top of S is the first to be inserted into T, and
element at the bottom of S ends up at the top of T. */
    stack stk1 = stack_new(10);
    stack *S=&stk1;

    stack stk2 = stack_new(10);
    stack *T=&stk2;

    transfer(S,T);

/*5.Implement a function that reverses a list of elements by pushing them onto a stack in one order,
and write them back to the list in reversed order.*/
    reverseElement(S,T);

/*6. Modify ArrayStack implementation so that the stack’s capacity is limited to maxlen elements. If
push is called when the stack is at full capacity, throw a Full exception. */
    CheckStackFull();

/*7. Implement a transfer function and two temporary stacks, to replace the contents
of a given stack S with those same elements, but in reverse order.*/
    TwoTemporaryStacks();

    return 0;
}

