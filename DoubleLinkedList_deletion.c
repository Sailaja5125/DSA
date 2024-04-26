#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *prev;
  struct node *next;
}*n1,*n2,*n3,*n4,*n5;

struct node * create_node(int data){
  struct node *head = (struct node *)malloc(sizeof(struct node));
  head->next= NULL;
  head->data =data;
  head->prev= NULL;
}
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
struct node *insert_index(struct node *head ,int data, int index){
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = data;
  struct node *p = head;
  int i =0 ;
  while(i < index-1){
    p = p->next;
    i++;
  }
  ptr->next = p->next;
  p->next = ptr;
  return ptr;
}
int delete_element(struct node *head ,int data){
  struct node *ptr = head;
  struct node *p = head->next; // this is gonna point the deleting element 
  while (p!=NULL && ptr->data+1<data)
  {
    p = p->next;
    ptr=ptr->next; 
  }
  // we need to update its previous as we are deleting a ptr
  ptr->next->prev = ptr;  
  ptr->next = p->next;
  free(p);
return ptr->data;
}

void main(){
  n1 = create_node(12);
  n2 = create_node(13);
  n3 = create_node(14);
  n4 = create_node(15);
  n5 = create_node(16);

  n1->next = n2;
  n1->prev = NULL;

  n2->next = n3;
  n2->prev = n1;
  
  n3->next = n4;
  n3->prev = n2;
  
  n4->next = n5;
  n4->prev = n3;

  n5->next = NULL;
  n5->prev = n4;
  
traverse_front(n1);  
insert_index(n1,45,3);
printf("\n");
traverse_front(n1);  
printf("\n");
delete_element(n1,14);  
traverse_front(n1);  

}
