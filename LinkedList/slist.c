#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "slist.h"
#include<stdio.h>
slist slist_new()
{
	slist s={NULL,NULL,0};
	return s;
}
static Node* slist_new_node(int32_t element)
{
	Node* new_node=(Node*)malloc(sizeof(Node));
	new_node->data=element;
	new_node->next=NULL;
	return new_node;
}
slist* slist_add_head(slist* list,int32_t element )
{
	assert(list!=NULL);
	Node* new_node=slist_new_node(element);
	new_node->next=list->head;
	list->head=new_node;
	if(list->tail==NULL)
	{
		list->tail=new_node;
	}
	++list->length;
	return list;
}
uint32_t slist_length(slist* list)
{
	assert(list!=NULL);
	return list->length;
}
uint32_t slist_lookup(slist* list,int32_t key)
{
	assert(list!=NULL);
	Node* cur;
	for(cur=list->head;cur!=NULL;cur=cur->next)
	{
		if(cur->data==key)
			break;
	}
	return (cur!=NULL);
}

void display(slist *list)
{
	Node* cur;
	cur=list->head;
	while(cur!=NULL)
	{
		printf("%d->",cur->data);
		cur=cur->next;
	}
	printf("\n");
}

slist* slist_delete_head(slist* list)
{
	assert(list!=NULL);
	Node* temp;
	temp=list->head;
	free(temp);
	temp=temp->next;
	list->head=temp;
	--list->length;
	return list;
}
slist* slist_delete_tail(slist* list)
{
	Node* cur;
	Node* prev;
	cur=list->head;
	while(cur->next!=NULL)
	{
		prev=cur;
		cur=cur->next;
	}
	free(cur);
	prev->next=NULL;
	list->tail=prev;
	--list->length;
	return list;

}
slist* reverse_list(slist* list)
{
	Node* cur;
	Node* prev;
	Node* temp;
	cur=list->head;
	temp=list->head;
	prev=NULL;
	while(cur!=NULL)
	{
	    temp=temp->next;
	    cur->next=prev;
	    prev=cur;
	    cur=temp;
	}
	list->head=prev;
	return list;


}
slist* slist_spec_ele_delete(slist* list,int32_t element)
{
	Node* cur;
	Node* prev;
	cur=list->head;
	if(cur->data==element)
	{
		list->head=cur->next;
		free(cur);
		return list;
	}
	while(cur->data!=element)
	{
		prev=cur;
		cur=cur->next;
	}
	prev->next=cur->next;
	free(cur);
	--list->length;
	return list;

}
slist* slist_add_tail(slist* list,int32_t element)
{
	Node* new_node;
	Node* cur;
	cur=list->head;
	new_node=slist_new_node(element);
	list->tail=new_node;
	if(list->head==NULL)
	{
		list->head=new_node;
	}
	while(cur->next!=NULL)
	{
		cur=cur->next;
	}
	cur->next=list->tail;
	++list->length;
	return list;
}
int32_t slist_max(slist* list)
{
	Node* cur;
	int32_t max;
	max=0;
	for(cur=list->head;cur!=NULL;cur=cur->next)
	{
		if(max<cur->data)
		{
		max=cur->data;
		}
	}
	return (max);
}
int32_t slist_min(slist* list)
{
	Node* cur;
	int32_t min;
	cur=list->head;
	min=cur->data;
	for(cur=list->head;cur!=NULL;cur=cur->next)
	{
		if(min>cur->data)
		{
		min=cur->data;
		}
	}
	return (min);
}
slist* slist_spec_ele(slist *list, int32_t element,int32_t spec_ele)
{
    assert(list!=NULL);
    Node *new_node=slist_new_node(element);
    Node *temp;
    for(temp=list->head;temp!=NULL;temp=temp->next)
    {
        if(temp->data==spec_ele)
        {
            new_node->next=temp->next;
            temp->next=new_node;
            if(temp->next==NULL)
            {
                assert(temp->next==NULL);
                list->tail=new_node;
            }
        }

    }
    ++list->length;
    return list;

}
uint32_t list_compare(slist *list1,slist *list2)
{
    assert(list1!=NULL);
    assert(list2!=NULL);
    Node *temp1,*temp2;
    temp1=list1->head;
    temp2=list2->head;
    while(temp1!=NULL && temp2!=NULL)
    {
      
        if(temp1->data != temp2->data)
        {
            return 0;
      
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return 1;
}
slist* union_twolist(slist *union_list,slist *list1,slist *list2)
{
    assert(list1!=NULL);
    assert(list2!=NULL);

    Node *temp1,*temp2;
    temp1=list1->head;
    temp2=list2->head;

    while(temp1!=NULL)
    {
        union_list = slist_add_head(union_list,temp1->data);
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        if(!(slist_lookup(list1, temp2->data)))
        {
            union_list = slist_add_tail(union_list,temp2->data);
        }
        temp2=temp2->next;
    }
    return union_list;
}
slist* intersection_twolist(slist *inter_list,slist *list1,slist *list2)
{
    assert(list1!=NULL);
    assert(list2!=NULL);

    Node *temp1,*temp2;
    temp1=list1->head;
    temp2=list2->head;
    while(temp1!=NULL)
    {
        if(slist_lookup(list2, temp1->data))
        {
            inter_list = slist_add_head(inter_list,temp1->data);
        }
        temp1=temp1->next;
    }
return inter_list;
}

