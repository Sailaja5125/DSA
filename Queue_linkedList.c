#include<stdio.h>
#include<stdlib.h>
struct lq
{
 int data;
 struct lq *next;
}*f,*r;
// Enque
void Enque(int data){
 struct lq *ptr = (struct lq*)malloc(sizeof(struct lq));
 if (ptr==NULL)
 {
   printf("the queue is overflow");
 }
 else
 {
    ptr->data = data;
    if (f==NULL)
    {
       f = r = ptr;
       f->next = r->next = NULL;
    }
    else
    {
        r->next = ptr;
        r = ptr;
        r->next = NULL;
    }
 }
}

void traverse(){
    do
    {
        printf("%d\t",r->data);
        r = r->next;
    } while (r!=NULL);
    
}
// dequeue
int Dequeue(){
    int value;
    struct lq *ptr= f;
    if (f==NULL)
    {
       printf("queue is underflow");
    }
    else
    {
        f = f->next;
        value = ptr->data;
        free(ptr);
    }
    return value;
}
int main(){
Enque(12);  // this is deleted first
Enque(13);
Enque(14);
Enque(15);
traverse();
printf("%d",Dequeue());

    return 0;
}
