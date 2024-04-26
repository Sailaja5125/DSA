#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
}*n1 ,*n2 ,*n3 ,*n4;

void traverse(struct node *head){
  struct node *ptr = head;
  do
  {
    printf("%d\t",ptr->data);
    ptr = ptr->next;
  } while(ptr!=head);
}
struct node *insert_index(struct node *head ,int index , int data){
  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  ptr->data = data;
  struct node *temp = head; 
  int i = 0 ; 
  while (i<index-1)
  {
    temp = temp->next;
    i++;
  }
  ptr->next = temp->next;
  temp->next = ptr;
  return ptr;
}

void main()
{
n1 =(struct node*)malloc(sizeof(struct node));
n2 = (struct node*)malloc(sizeof(struct node));
n3 = (struct node*)malloc(sizeof(struct node));
n4 = (struct node*)malloc(sizeof(struct node));

n1->data = 12;
n1->next = n2;

n2->data = 13;
n2->next = n3;

n3->data = 14;
n3->next = n4;

n4->data = 11;
n4->next = n1;
 
 traverse(n1);
 insert_index(n1,4,23);
 printf("\n");
 traverse(n1);

}
