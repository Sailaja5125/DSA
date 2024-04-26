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
struct node *insert(struct node *head , int data){
  struct node * ptr = (struct node *)malloc(sizeof(struct node));
   ptr->data = data;
   struct node *p = head->next;
   while(p->next!=head){
    p = p->next;
   } 
   p->next = ptr;
   ptr->next = head;
   ptr = head;
   return ptr;
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
   n1 = insert(n1,56);
   printf("after insertion\n");
   traverse(n1);
}
