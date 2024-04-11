// trees
// creating trees
#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree* create(int data){
    struct tree *root = (struct tree*)malloc(sizeof(struct tree));
    root->left = NULL;
    root->right = NULL;
    root->data = data;
return root;
}
// postorder traversal root->left ---> root->right -----> root
int traversal(struct tree *root){
 if (root!=NULL)
 {
    traversal(root->left);
    traversal(root->right);
    printf("%d\t",root->data);
 }
 
}

int main(){
struct tree *root = create(12);
struct tree *child1 = create(23);
struct tree *child2 = create(34);
struct tree *child11 = create(45);
struct tree *child12 = create(56);
struct tree *child21 = create(67);
struct tree *child22 = create(78);

root->left = child1;
root->right = child2;

child1->left = child11;
child1->right = child12;

child2->left = child21;
child2->right = child22;
traversal(root);
    return 0;
}