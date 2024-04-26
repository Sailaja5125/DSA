#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*n1,*n2,*n3,*n4;

void traverse(struct node *head){
    struct node *ptr = head;
    do
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    } while (ptr!=head);   
}
void main(){
  n1 = (struct node*)malloc(sizeof(struct node));
  n2 = (struct node*)malloc(sizeof(struct node));
  n3 = (struct node*)malloc(sizeof(struct node));
  n4 = (struct node*)malloc(sizeof(struct node));
   n1->data = 12;
   n1->next = n2;

   n2->data = 23;
   n2->next = n3;

     n3->data = 34;
   n3->next = n4;

     n4->data = 45;
   n4->next = n1;
   
   traverse(n1);
}
