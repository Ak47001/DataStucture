#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "binary.h"
void test_case()
{
    BST s =bst_newnode();
    BST *bin=&s;
    bin=bst_add_node(bin,45);
    bin=bst_add_node(bin,49);
    bin=bst_add_node(bin,80);
    bin=bst_add_node(bin,70);
    bin=bst_add_node(bin,20);
    bin=bst_add_node(bin,10);
    assert(bst_count(bin)==6);
    bin=bst_delete_node(bin,80);
    assert(bst_count(bin)==5);
    bst_inorder(bin);
    bst_preorder(bin);
    bst_post_order(bin);
    ascending_order(bin);
    descending_order(bin);
    bst_min(bin);
    bst_max(bin);
    bst_height(bin);
    bst_level_order(bin);
}
int main()
{
    test_case();
    return 0;
}
