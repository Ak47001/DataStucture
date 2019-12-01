#ifndef _INCLUDED_SLIST_
#define _INCLUDED_SLIST_
#include<stdint.h>
typedef struct _node_ Node;
typedef struct _slist_ slist;
struct _node_{
	int32_t data;
	Node* next;
};
struct _slist_{
	Node* head;
	Node* tail;
	uint32_t length;
};
/*public interface for user*/
slist slist_new();
uint32_t slist_length(slist *list);
uint32_t slist_lookup(slist *list,int32_t key);
slist* slist_add_head(slist *list,int32_t element);
slist* slist_add_tail(slist *list,int32_t element);
slist* slist_delete_head(slist *list);
slist* slist_delete_tail(slist *list);
int32_t slist_min(slist *list);
int32_t slist_max(slist *list);
slist* slist_spec_ele(slist *list, int32_t element,int32_t spec_ele);
slist* slist_spec_ele_delete(slist *list, int32_t spec_ele);
uint32_t list_compare(slist *list,slist *list1);
slist* reverse_list(slist *list);
slist* union_twolist(slist *union_list,slist *list1,slist *list2);
slist* intersection_twolist(slist *intersection_list,slist *list1,slist *list2);
/*
slist* unique_slist(slist* list,uint32_t element);
*/
void display(slist *list);
#endif


