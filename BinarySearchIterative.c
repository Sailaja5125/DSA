/// binary search in iterative approach
#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree *createtree(int data)
{
    struct tree *root = (struct tree *)malloc(sizeof(struct tree));
    root->left = NULL;
    root->data = data;
    root->right = NULL;

    return root;
}
int isBst(struct tree *root)
{
    static struct tree *prev = NULL; // static because it preserves its actual value even its out of its scope / i.e undergoing through recursion
    if (root != NULL)                // if root has child nodes then perform the below function
    {
        if (!isBst(root->left)) // checking for the left node through recursive
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data) // if prev is != null and root->data < = previous->data which is the previous root
        {
            return 0;
        }
        prev = root;
        return isBst(root->right);
    }
    else
    {
        return 1;
    }
}
//  binary searching trees through iterativesearch 
struct tree *iterativeSearch(struct tree *root , int key ){
    if (root==NULL)
    {
        return 0;
    }
    if (key == root->data)
    {
        return root ;
    }
    else if (key < root->data)
    {
        root = root->left;
        while (root!=NULL)
        {
            if (key == root->data)
            {
                return root;
            }            
        }    
    }
    else
    {
        root = root->right;
        while (root!=NULL)
        {
            if (key == root->data)
            {
                return root ;
            }
        }    
    }
}
void inorder(struct tree *root)
{
    if (root != NULL) // if root is not equal to null it will print.
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct tree *root = createtree(5);
    struct tree *child1 = createtree(3);
    struct tree *child2 = createtree(6);
    struct tree *child11 = createtree(1);
    struct tree *child12 = createtree(4);
    root->left = child1;
    root->right = child2;

    child1->left = child11;
    child1->right = child12;

    child2->left = NULL;
    child2->right = NULL;

    if (isBst(root))
    {
        printf("is BST\n");
        if(iterativeSearch(root , 3)){
            printf("key found\n");
        }
        else
        {
            printf("key not found\n");
            
        }
        
    }
    else
    {
        printf("is not BST");
    }
    inorder(root);

    return 0;
}