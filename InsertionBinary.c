// insertion in binary tree..
#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree *createtree(int data)
{
    struct tree *root = (struct tree *)malloc(sizeof(struct tree));
    root->left = NULL;
    root->right = NULL;
    root->data = data;
    return root;
}
void insert(struct tree *root , int num){
    struct tree *prev = NULL;  // this travells the entire tree to check the place for the ptr to settle
    struct tree *ptr = createtree(num); // its the ptr which is being inserted with the data.
    while (root!=NULL)
    {
        prev = root ; 
        if (num == root->data )
        {
            printf("insertion in tree not possible\n");
            exit(0);
        }
        else if (num < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if(num < prev->data)
    {
        prev->left = ptr;
    }
    else
    {
        prev->right = ptr;
    }
    
}
void inorder(struct tree *root){
    if (root!=NULL)
    {    
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
    }
}
int main(){
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

    insert(root , 0);
    inorder(root);
}
