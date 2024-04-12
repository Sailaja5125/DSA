// Binary Search Tree >>>> Recursive approach.
#include <stdio.h>
#include <stdlib.h>
struct bst
{
    int data;
    struct bst *left;
    struct bst *right;
};
struct bst *createtree(int data)
{
    struct bst *root = (struct bst *)malloc(sizeof(struct bst));
    root->left = NULL;
    root->right = NULL;
    root->data = data;
    return root;
}
// binary search recursive approach
struct bst *binarysearch(struct bst *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        return binarysearch(root->left, key);
    }
    else
    {
        return binarysearch(root->right, key);
    }
}
int main()
{
    struct bst *root = createtree(5);
    struct bst *child1 = createtree(3);
    struct bst *child2 = createtree(6);
    struct bst *child11 = createtree(1);
    struct bst *child12 = createtree(4);
    root->left = child1;
    root->right = child2;

    child1->left = child11;
    child1->right = child12;

    child2->left = NULL;
    child2->right = NULL;
    
    if (binarysearch(root, 7))
    {
        printf("key found in the tree\n");
    }
    else
    {
        printf("key not found in the tree\n");
    }

    return 0;
}
