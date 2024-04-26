#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node*next;
}*n1,*n2,*n3,*n4;
void traverse(struct node *head){
  struct node *ptr = head;
  do{
    printf("%d\t",ptr->data);
    ptr = ptr->next;
  }while(ptr!=head);
}
struct node *insert_last(struct node *head , int data){
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = data;
  struct node *temp = head;
  while (temp->next!=head)
  {
    temp = temp->next;
  }
  temp->next = ptr;
  ptr->next = head;
  return ptr;
}
int delete_element(struct node *head , int element){
  struct node *ptr = head;
  struct node *p = head->next; // this points to the deleting index 
  while(p!=head && ptr->data+1!=element){
    p = p->next;
    ptr = ptr->next;
  }
  ptr->next = p->next;
  free(p);
  return ptr->data; 
}

void main(){
n1 = (struct node *)malloc(sizeof(struct node));
n2 = (struct node *)malloc(sizeof(struct node));
n3 = (struct node *)malloc(sizeof(struct node));
n4 = (struct node *)malloc(sizeof(struct node));

n1->data = 1;
n1->next = n2;

n2->data = 2;
n2->next = n3;

n3->data = 3;
n3->next = n4;

n4->data = 4;
n4->next = n1;

traverse(n1);
// insertion 100 elements
for(int i = 5 ; i<= 20 ; i++){
insert_last(n1,i);
}
printf("\n");
traverse(n1);
// deleting even elements
for(int i = 1 ; i<=20 ; i++){
  if(i%2==0){
    delete_element(n1,i);
  }
}
printf("\n");
traverse(n1);

}
