#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*n1,*n2,*n3;
void traverse(struct node *head){
    while(head!=NULL){
        printf("%d\t",head->data);
        head = head->next;
    }
}
struct node *delete_first(struct node *head){
   struct node *ptr = head;
   head = head->next;
   free(ptr);
   return head;
}
struct node *delete(struct node *head , int index){
    struct node *ptr = head; 
    struct node *p = head->next; // this pointer points the deleting node 
    for(int i = 0 ; i< index-1 ; i++){
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = p->next;
    free(p);
    return head;
}

void main(){
n1 = (struct node *)malloc(sizeof(struct node));
n2 = (struct node *)malloc(sizeof(struct node));
n3 = (struct node *)malloc(sizeof(struct node));
n1->data = 12;
n1->next = n2;

n2->data = 24;
n2->next = n3;

n3->data = 34;
n3->next = NULL;

traverse(n1);
//  n1 = delete_first(n1);
 n1 = delete(n1,2); 
 printf("\n");
traverse(n1);


}
