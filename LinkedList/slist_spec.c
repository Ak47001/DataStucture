/*
 *	Author : Deepak
 *	Date   : 23 August 2019 
 *	Specification file for Single Linked List
 *	Contain test cases to test various functionalities
 *	of Single Linked List.
*/


#include <assert.h>
#include "slist.h"
#include<stdlib.h>
#include<stdio.h>
/* test case to check creation of empty slist variable */
void test_empty_list()
{
	slist s = slist_new();
	slist *list = &s;
	assert (slist_length(list) == 0);
}

/*	test case to check adding node from 'head' position
 *	finding length of list and lookup functions
*/
void test_addition_at_head()
{
	slist s = slist_new();
	slist k = slist_new();
	slist u = slist_new();
	slist i = slist_new();
	slist *inter_list=&i;
	slist *union_list =&u;
	slist *list = &s;
	slist *list1= &k;
	list = slist_add_head(list, 10);
	assert(slist_length(list)==1);
	list = slist_add_head(list, 20);
	list = slist_add_head(list, 30);
	list = slist_add_head(list, 40);
	list = slist_delete_head(list);
	list = slist_add_head(list, 50);
	list = slist_add_tail(list, 50);
	assert (slist_length(list) == 5);
	assert (slist_lookup(list, 30));
	display(list);
	list=slist_delete_head(list);
	display(list);
	list=slist_delete_tail(list);
	display(list);
	list = slist_delete_tail(list);
//2.      Add methods to Q1 to find maximum and minimum elements in the list.
	list = slist_add_head(list, 10);
	list = slist_add_head(list, 100);
	int32_t min,max;
	assert(slist_min(list)==10);
	assert(slist_max(list)==100);	

//3.      Modify Q1 such that one can add a new element after any specified element.
	
	list = slist_spec_ele(list,50,20);
	display(list);
//4.      Modify Q1 such that one can delete any specified element from the list.

	list = slist_spec_ele_delete(list,20);
	display(list);
//5.      Write a method to reverse the elements in the same list.
	list = reverse_list(list);
	display(list);
	list1 = slist_add_head(list1, 40);
	list1 = slist_add_head(list1, 80);
	list1 = slist_add_head(list1, 70);
	list1 = slist_add_head(list1, 30);
	list1 = slist_add_head(list1, 10);
//6.to compare
	assert(list_compare(list,list1)==0);
	
//7. to union
	union_list=union_twolist(union_list,list1,list);
//8.to intersection
	inter_list=intersection_twolist(inter_list,list1,list);
	
}

int main()
{
	test_empty_list();
	test_addition_at_head();
	
	return 0;
}

/*
 *	Running your programs. Assume that already you have
 *	'slist.h', 'slist.c' and 'slist_spec.c' files.
 *
 *	gcc slist.c slist_spec.c -o slist
 *
 *	If you get errors, fix them. Otherwise you have exe file
 *	with name 'slist' (due to -o slist option used during compilation)
 *	
 *	Running exe file:	./a.out slist
 *	If you don't get any message in terminal, code executed perfectly
 *	( No news good news!!!!!!!)
 *
*/
