#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *prev;
  struct node *next;
}*n1,*n2,*n3,*n4,*n5;
void traverse_front(struct node *head){
  struct node *p = head;
  while (p!=NULL)
  {
    printf("%d\t",p->data);
    p = p->next;
  }  
}
void traverse_reverse(struct node *foot){
  struct node *f = foot ; 
  while (f!=NULL)
  {
    printf("%d\t",f->data);
    f = f->prev;
  }
  
}

void main(){
n1 = (struct node *)malloc(sizeof(struct node));
n2 = (struct node *)malloc(sizeof(struct node));
n3 = (struct node *)malloc(sizeof(struct node));
n4 = (struct node *)malloc(sizeof(struct node));
n5 = (struct node *)malloc(sizeof(struct node));

n1->data = 12;
n1->prev = NULL;
n1->next = n2;

n2->data = 13;
n2->prev = n1;
n2->next = n3;

n3->data = 14;
n3->prev = n2;
n3->next = n4;

n4->data = 15;
n4->prev = n3;
n4->next = NULL;
// front traverse 
traverse_front(n1);  
printf("reverse is \n");
traverse_reverse(n4);
}
