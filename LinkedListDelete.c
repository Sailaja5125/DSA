#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
}*n1,*n2,*n3,*n4;
// traverse
void traverse(struct node *head){
  while(head!=NULL){
    printf("%d\t",head->data);
    head = head->next;
  }
}
// delete the node by using given data
int delete(struct node *head , int data){
  struct node *ptr = head;
  struct node *p = head->next; // this pointer points exactly to the deleting node
  while(p!=NULL && ptr->data+1!=data){
    p = p->next; 
    ptr = ptr->next;
  }
  ptr->next = p->next ; 
  free(p);
  return ptr->data;
}

void main(){
n1 = (struct node *)malloc(sizeof(struct node)); 
n2 = (struct node *)malloc(sizeof(struct node));
n3 = (struct node *)malloc(sizeof(struct node));
n4 =(struct node *)malloc(sizeof(struct node));

n1->data = 12;
n1->next = n2;

n2->data = 13;
n2->next = n3;

n3->data = 14;
n3->next = n4;

n4->data = 15;
n4->next = NULL;

traverse(n1);
delete(n1 ,15);
printf("\n");
traverse(n1);

}
