#include <stdint.h>
#include <assert.h>
#include "heap.h"
#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

void test_sort( int32_t data[], uint32_t len) 
{
	uint32_t idx;
	for (idx = 1; idx <= len; ++idx) {
		assert (data[idx] <= data[idx+1]);		
	}
}

void test_heap()
{
	int32_t datatm[] = { 630, 700, 730, 800, 900, 930, 1000, 530, 1100, 1130, 1200};
	int32_t datanum[] = { 151, 152, 154, 157, 196, 187, 1156, 193, 161, 117, 173};
	int32_t datatf[] = { 645, 715, 745, 815, 915, 945, 1015, 1045, 1115, 1145, 1215};
	Heap heap = heap_new(datatm,datanum,datatf, 10);
	//printf("%d",heap.datatm[1]);	
	//heap_insert(&heap, 47);
	//heap_test(&heap);
	//assert(heap_get_max(&heap) == 93);
	//assert(heap_extract_max(&heap) == 93);
	//heap_test(&heap);
	//assert(heap_size(&heap) == 10);

	heap_sort(&heap);
//before scheduling
	display(&heap,10);
	//test_sort(heap.datatm, 10);
	shift_heap(&heap,10);
//after scheduling
	heap_sort(&heap);
	display(&heap,10);

}

int main()
{
	test_heap();
	return 0;
}
