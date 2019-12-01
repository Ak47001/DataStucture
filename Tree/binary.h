#include<stdint.h>
#include<stddef.h>
#ifndef _INCLUDED_BST_
#define _INCLUDED_BST_
typedef struct _tree_node_ TreeNode;
typedef struct _bst_ BST;
struct _tree_node_{
    int32_t data;
    TreeNode *left;
    TreeNode *right;
};
struct _bst_{
    TreeNode *root;
    uint32_t mass;
};
BST bst_newnode();
uint32_t bst_count(BST *tree);
BST* bst_add_node(BST *tree,int32_t element);
BST* bst_delete_node(BST *tree,int32_t element);
uint32_t bst_lookup(BST *tree,int32_t key );
void bst_inorder(BST* tree);
void bst_preorder(BST* tree);
void bst_post_order(BST* tree);
void bst_level_order(BST* tree);
void bst_height(BST* tree);
void ascending_order(BST* tree);
void descending_order(BST* tree);
void bst_min(BST* tree);
void bst_max(BST* tree);
void bst_ht(BST* tree);

/*queue purpose*/
/*
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
*/
/*end------------------- **************/

#endif // _INCLUDED_BST_
