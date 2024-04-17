// Deletion in Binary Tree
// deleting the leaf node
// deleting the parent node
// deleting the root node
#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree *createtree( int data ){
    struct tree *root = (struct tree *)malloc(sizeof(struct tree));
    root->right = NULL;
    root->left = NULL;
    root->data = data;

  return root;
}
struct tree *inorderPre(struct tree *root){  // ipre is found in the left subtree
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}
struct tree * deletion(struct tree *root , int data){
    struct tree *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    
 if (data < root->data)
 {
    root->left = deletion(root->left , data);
 }
 else if (data > root->data)
 {
    root->right = deletion(root->right , data);
 }
 // deletion startergy
 else  // if data == root->data
 {
     ipre = inorderPre(root); // inorder predessor is found in the left subtree of the root 
    root->data = ipre->data;  
    root->left = deletion(root->left , ipre->data);
 }
 
  return root;
     
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
    
    inorder(root);
    deletion(root , 5);
    printf("\n");
    inorder(root); // 4 is deleted 
    return 0;
}