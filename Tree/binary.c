#include "binary.h"
#include "queues.h"
#include<stdint.h>
#include<stddef.h>
#include<assert.h>
#include<malloc.h>
#include<stdio.h>
BST bst_newnode()
{
    BST tree={NULL,0};
    return tree;
}
static TreeNode* _make_new_Node(int32_t element)
{
    TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode));
    node->data=element;
    node->left=NULL;
    node->right=NULL;
    return node;
}
uint32_t bst_count(BST *tree)
{
    return tree->mass;
}
BST* bst_add_node(BST *tree,int32_t element)
{
    assert(tree!=NULL);
    TreeNode *cur,*parent;
    cur=parent=tree->root;
    while(cur!=NULL && cur->data!=element)
    {
        parent=cur;
        if(cur->data<element)
        {
            cur=cur->right;
        }
        else if(cur->data>element)
        {
            cur=cur->left;

        }
    }
        if(cur==NULL)
        {

            TreeNode *newnode=_make_new_Node(element);
            if(parent==NULL)
            {

                tree->root=newnode;
            }
            else if(parent->data<element)
            {
                parent->right=newnode;
            }
            else
            {
                parent->left=newnode;
            }
            tree->mass++;
        }

        return tree;

}
uint32_t bst_lookup(BST *tree,int32_t key)
{

    assert(tree!=NULL);
    TreeNode *temp=tree->root;
    while(temp!=NULL && temp->data!=key)
    {
        if(temp->data>key)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    return (temp!=NULL);

}
static TreeNode* _findmin_(TreeNode *node)
{
    if(node->left==NULL)
    {
        return node;
    }
    else
        return _findmin_(node->left);
}
static TreeNode* _findmax_(TreeNode *node)
{
    if(node->right==NULL)
    {
        return node;
    }
    else
        return _findmax_(node->right);
}
void bst_min(BST *tree)
{
    TreeNode *node;
    node=_findmin_(tree->root);
    printf("%d",node->data);
    printf("\n");
}

void bst_max(BST *tree)
{
    TreeNode *node;
    node=_findmax_(tree->root);
    printf("%d",node->data);
    printf("\n");
}
static int32_t tree_ht(TreeNode *node)
{
    if(node==NULL)
    {
        return 0;
    }
    else{
        int leftsd,rightsd;
        leftsd=tree_ht(node->left);
        rightsd=tree_ht(node->right);
        if(leftsd>rightsd)
        {
            return leftsd+1;
        }
        else
            return rightsd+1;
    }
}
void bst_height(BST* tree)
{
    int32_t ht;
    ht=tree_ht(tree->root);
    printf("%d",ht);
    printf("\n");
}
static TreeNode* _delete_(BST *tree,TreeNode *node,int32_t key)
{
    TreeNode *temp;
    if(node==NULL)
    {
        return node;
    }
    else if(key<node->data)
    {
        node->left=_delete_(tree,node->left,key);
    }
    else if(key>node->data)
    {
        node->right=_delete_(tree,node->right,key);

    }
    else if(node->left && node->right)
    {
        temp=_findmin_(node->right);
        node->data=temp->data;
        node->right=_delete_(tree,node->right,node->data);
    }
    else
    {
        temp=node;
        if(node->right==NULL)
        {
            node=node->left;
        }
        else
        {
            node=node->right;
        }
        free(temp);
        --tree->mass;
    }
    return node;
}


BST* bst_delete_node(BST *tree,int32_t element)
{
    assert(tree!=NULL);
    tree->root=_delete_(tree,tree->root,element);
    return tree;
}

static void _inorder_(TreeNode *node)
{
    if(node){
        _inorder_(node->left);
        printf("%d\t",node->data);
        _inorder_(node->right);
    }

}
void bst_inorder(BST *tree)
{
    assert(tree!=NULL);
    _inorder_(tree->root);
    printf("\n");
}
static void _preorder_(TreeNode *node)
{
    if(node){
        printf("%d\t",node->data);
        _preorder_(node->left);
        _preorder_(node->right);
    }
}
void bst_preorder(BST *tree)
{
    assert(tree!=NULL);
    _preorder_(tree->root);
    printf("\n");
}
static void _postorder_(TreeNode *node)
{
    if(node){

        _postorder_(node->left);
        _postorder_(node->right);
        printf("%d\t",node->data);
    }
}
void bst_post_order(BST *tree)
{
    assert(tree!=NULL);
    _postorder_(tree->root);
    printf("\n");
}

void ascending_order(BST *tree)
{
    bst_inorder(tree);
}
static void _descend_(TreeNode *node)
{
    if(node){
        _descend_(node->right);
        printf("%d\t",node->data);
        _descend_(node->left);

    }

}
void descending_order(BST *tree)
{
    assert(tree!=NULL);
    _descend_(tree->root);
    printf("\n");

}


void bst_level_order(BST *tree)
{
    assert(tree!=NULL);
    TreeNode *node;
    queue bst_q=queue_new(tree->mass);
    queue *q=&bst_q;
    queueresult res;
    q=queue_add(q,tree->root,&res);
    while(!queue_empty(q))
    {
        queue_delete(q,&res);
        node=(TreeNode*)res.data;
        if(node->left){
            queue_add(q,node->left,&res);
        }
        if(node->right)
        {
            queue_add(q,node->right,&res);
        }
        printf("%d\t",node->data);
    }
}

