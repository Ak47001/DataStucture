#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "heap.h"
#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>


static void _swap_(int32_t *data1, int32_t *data2) {
	int32_t temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

static void _heapify_ (int32_t datatm[],int32_t data_num[],int32_t data_tf[], uint32_t len, uint32_t parent) {
	assert (len > 0 && len < HEAP_MAX_SIZE && parent > 0 );

	uint32_t child = 2 * parent;

	while (child <= len) {
		if (child + 1 <= len) {
			if (datatm[child+1] > datatm[child]){
				++child;
			}
		}
		if (datatm[parent] >= datatm[child]) {
			break;
		}
		_swap_(&datatm[parent], &datatm[child]);
		_swap_(&data_num[parent], &data_num[child]);
		_swap_(&data_tf[parent], &data_tf[child]);
		parent = child;
		child = 2 * parent;
	}
}

static void _test_heap_(int32_t data[], uint32_t len) {

	for (uint32_t child = len; child > 1; --child) {
		assert(data[child] <= data[child/2]);
	}

}

Heap*	heap_test(Heap *heap)
{
	_test_heap_(heap->datatm, heap->size);
}

Heap 	heap_new(int32_t datatm[],int32_t datanum[],int32_t datatf[], uint32_t len) {
	assert (len > 0 && len < HEAP_MAX_SIZE);

	Heap heap;
	uint32_t idx = len/2;
	for (idx = len/2; idx > 0; --idx) {
		_heapify_(datatm,datanum,datatf, len, idx);
	}
	heap.size = len;
	memcpy(heap.datatm, datatm, (len+1) * sizeof(int32_t));
	memcpy(heap.datanum, datanum, (len+1) * sizeof(int32_t));
	memcpy(heap.datatf, datatf, (len+1) * sizeof(int32_t));
	_test_heap_(heap.datatm, heap.size);

	return heap;
}

Heap*	heap_sort(Heap *heap) {
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);

	uint32_t idx = heap->size;

	for (idx = heap->size; idx > 1; idx--) {
		_swap_(&heap->datatm[idx], &heap->datatm[1]);
		_swap_(&heap->datanum[idx], &heap->datanum[1]);
		_swap_(&heap->datatf[idx], &heap->datatf[1]);
		_heapify_(heap->datatm,heap->datanum,heap->datatf, idx-1, 1);
	}

	return heap;
}


Heap*	heap_insert(Heap *heap, int32_t time,int32_t num,int32_t takeoff)
{
	assert (heap->size > 0 && heap->size+1 < HEAP_MAX_SIZE);

	++heap->size;
	uint32_t parent = heap->size/2;
	uint32_t loc = heap->size;

	while ( loc > 1 && heap->datatm[parent] < time) {
		heap->datatm[loc] = heap->datatm[parent];
		heap->datanum[loc] = heap->datanum[parent];
		heap->datatf[loc] = heap->datatf[parent];
		loc = parent;
		parent = parent/2;
	}
	heap->datatm[loc] = time;
	heap->datanum[loc]=num;
	heap->datatf[loc]=takeoff;
	return heap;

}

int32_t		heap_get_max(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);
	return heap->datatm[1];

}

int32_t		heap_extract_max(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);

	int32_t max = heap->datatm[1];	
	_swap_(&heap->datatm[1], &heap->datatm[heap->size]);
	--heap->size;
	_heapify_(heap->datatm,heap->datanum,heap->datatf, heap->size, 1);

	return max;
}

uint32_t	heap_size(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);
	return heap->size;
}
void shift_heap(Heap* heap,int32_t len)
{
	int32_t i=0;
	while(len>i)
	{
		if(heap->datatm[i]>=0 && heap->datatm[i]<=1130)
		{
			
			printf("%d\t",heap->datatm[i]);
			printf("%d\t",heap->datanum[i]);
			printf("%d\t",heap->datatf[i]);
			heap->datatm[i]=heap->datatm[i]+1200;//shifting process
			heap->datatf[i]=heap->datatf[i]+1215;
		}
		printf("\n");

		i++;
	}
	
}
void display(Heap *heap,int32_t len)
{
	int32_t i;
	for(i=0;i<len;i++)
	{
		printf("%d\t",heap->datatm[i]);
		printf("%d\t",heap->datanum[i]);
		printf("%d\t",heap->datatf[i]);
	}
}

