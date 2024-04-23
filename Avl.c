#include<stdio.h>
#include<stdlib.h>
struct tree {
    int data;
    struct tree *left ;
    struct tree *right;
    int height;
};

int max(int a , int b){
    return a>b?  a :  b;
}
// get Height
int getHeight(struct tree *root){
    if (root==NULL)
    {
        return 0;
    }
    return root->height;
}
struct tree *createtree(int data){
 struct tree *root  = (struct tree *)malloc(sizeof(struct tree));
 root->left= NULL;
 root->right = NULL;
 root->data = data;
 root->height = 1;
 return root;
}
// balance factor
int balanceFactor(struct tree *root){
    if (root==NULL)
    {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

struct tree *rightRotate(struct tree *root){ // left rotation with respective to root;
// previous tree unrotated
    struct tree * x = root->left;
    struct tree *t2 = x->right;

    x->right  = root; // here we turned the root as x 
     root->left = t2;

    // updating heights
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // returning new root
}

struct tree *leftRotate(struct tree *root){ // right rotation with respective to root;
    struct tree *x = root->right;
    struct tree *t2 = x->left;

    x->left = root;
    root->right = t2;

    // updating heights
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // returning new root
}

struct tree *insert(struct tree *root, int key){
    if (root == NULL)
    {
        return createtree(key);
    }
    else if (root->data > key)
    {
        root->left = insert(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = insert(root->right, key);
    }
    else // equal keys are not allowed
    {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = balanceFactor(root);

    // Left Left Case
    if (balance > 1 && key < root->left->data)
    {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && key > root->right->data)
    {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
// traversal
void preorder(struct tree *root){
    if (root!=NULL)
    {    
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}
void main(){
 struct tree *root = NULL;
 root = insert(root , 1);
 root = insert(root , 2);
 root = insert(root , 4);
 root = insert(root , 5);
 root = insert(root , 6);
 root = insert(root , 3);


 preorder(root);
}