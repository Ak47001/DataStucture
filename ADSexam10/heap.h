#ifndef _INCLUDED_HEAP_
#define _INCLUDED_HEAP_
#include <stdint.h>
#include<stdlib.h>
//#include<conio.h>
#define HEAP_MAX_SIZE 32

typedef struct _heap_ Heap;
struct  _heap_
{
	uint32_t	size;
	int32_t		datatm[HEAP_MAX_SIZE];
	int32_t		datanum[HEAP_MAX_SIZE];
	int32_t		datatf[HEAP_MAX_SIZE];
	
};

Heap 		heap_new(int32_t datatm[],int32_t datanum[],int32_t datatf[], uint32_t len);
Heap*		heap_sort(Heap *heap);
Heap*		heap_insert(Heap *heap, int32_t time,int32_t num,int32_t takeoff);
Heap*		heap_test(Heap *heap);
int32_t		heap_get_max(Heap *heap);
int32_t		heap_extract_max(Heap *heap);
uint32_t	heap_size(Heap *heap);
void  shift_heap(Heap *heap,int32_t len);
void display(Heap *heap,int32_t len);

#endif
