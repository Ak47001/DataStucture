#include<stdint.h>
#include<assert.h>
#include<stddef.h>
#include"queue.h"
queue queue_new(uint32_t size)
{
	size=(size>0 && size<32)?size:MAX_DEPTH;
	queue q={size,0,0,0,{0}};
	return q;
}
uint32_t queue_full(queue *q)
{
    assert(q!=NULL);
    return (q->count==q->size);
}
uint32_t queue_empty(queue *q)
{
    assert(q!=NULL);
    return (q->count==0);
}
queue* queue_add(queue *q,int32_t element,queueresult *res)
{
	if(q->count<q->size)
	{
		q->data[q->head]=element;
		q->head=(q->head+1)%q->size;
		++q->count;
		res->data=element;
		res->status=QUEUE_OK;
	}
	else
	{
		res->status=QUEUE_FULL;
	}
	assert((res->status==QUEUE_OK)||(q->count==q->size));
	return q;
}
queue* queue_delete(queue *q,queueresult *res)
{
	if(q->count>0)
	{
		res->data=q->data[q->tail];
		q->tail=(q->tail+1)%q->size;
		--q->count;
		res->status=QUEUE_OK;
	}
	else
	{
		res->status=QUEUE_EMPTY;
	}
	assert((res->status==QUEUE_OK)||(q->count==0));
	return q;
}



