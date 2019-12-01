#include<stdint.h>
#include<assert.h>
#include<stddef.h>
#include<stddef.h>
#define MAX_DEPTH 32
typedef struct _queue_ queue;
typedef struct _queueresult_ queueresult;
struct _queue_{
	uint32_t size;
	uint32_t count;
	uint32_t head;
	uint32_t tail;
	int32_t data[MAX_DEPTH];
};
struct _queueresult_
{
	int32_t data;
	uint32_t status;

};
#define QUEUE_OK 1
#define QUEUE_FULL 2
#define QUEUE_EMPTY 3

queue queue_new(uint32_t size);
uint32_t queue_full(queue *q);
uint32_t queue_empty(queue *q);
queue* queue_add(queue *q,int32_t element,queueresult *res);
queue* queue_delete(queue *q,queueresult *res);

