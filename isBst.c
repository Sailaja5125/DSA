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
int checkbst(struct bst *root)
{
  if(root!=NULL){
     static struct bst *prev = NULL;
     if(!checkbst(root->left)){
        return 0;
     }
     if(prev!=NULL&& root->data<=prev->data){
        return 0;
     }
     prev = root;
     return checkbst(root->right);
  } 
  else{
    return 1;
  }  
}

void inorder(struct bst *root){
  if (root!=NULL) // if root is not equal to null it will print.
  {
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
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

 if (checkbst(root))
 {
   printf("is bst");
 }
else
{
    printf("is not bst");
}

//   inorder(root);

    return 0;
}
