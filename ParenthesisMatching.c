#include<stdio.h>
#include<stdlib.h>
struct stack{
  int *arr;
  int top;
  int size;
};
int isEmpty(struct stack *top){
  if (top->top == -1)
  {
  return 1;
  }
  return 0;
}
int isFull(struct stack *top){
  if (top->top == top->size)
  {
  return 1;
  }
  return 0;
}
int push(struct stack *top ,char data){
if (isFull(top))
{
  printf("stack overflow\n");
}
else{
  top->top++;
  top->arr[top->top] = data;
  return top->top;
}
}
int pop(struct stack *top){
if (isEmpty(top))
{
  printf("stack underflow\n");
}
else{
  char value = (top->arr)[top->top];
  top->top--;

}
}
int parenthesis(struct stack *top , char* ch){
for(int i = 0 ; ch[i]!='\0' ; i++){
   if(ch[i]=='('){
    push(top,ch[i]);
   }
   else if(ch[i]==')'){
    if (isEmpty(top))
    {
      return 0;
    }
    else{
      pop(top);
    }
   }
}
if(isEmpty(top)){
  return 1;
}
else{
  return 0;
}
}
void traverse(struct stack *top , int size){
 for(int i = 0 ; i<=size ; i++){
  printf("%c\t",top->arr[i]);
 }
}
void main(){
struct stack *s;
s->size = 5;
s->top = -1;
s->arr = (int *)malloc(s->size * sizeof(int));

char *c = "()()())";
if (parenthesis(s,c))
{
  printf("parenthesis matched");
}
else
{
  printf("parenthesis unmatched");
}

}
