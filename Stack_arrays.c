#include<stdio.h>
#include<stdlib.h>
struct stack{
int *arr;
int top ; 
int size;
};
int isEmpty(struct stack *st){
  if(st->top == -1){
    return 1;
   }
  return 0;
}
int isFull(struct stack *st){
  if(st->top == st->size-1){
    return 1;
  }
  return 0;
} 
int push(struct stack *st , int value){
  if(isFull(st)){
    printf("stack overflow");
  }
  else{
    st->top++;
    st->arr[st->top] = value;
  return st->top;
  }
}

int peek(struct stack *st , int index){
  if(st->top - index < 0){
    printf("invalid index");
  }
  else{
    return st->arr[st->top-index];
  }
}
int show(struct stack *st , int top){
  if(isEmpty(st)){
    printf("stack overflow");
  }
  else{
    for(int i = top ; i>=0 ; i--){
      printf("%d\t",(st->arr)[i]);
    }
  }
}

int main(){
struct stack *s ;
s->size = 5;
s->top = -1;
s->arr = (int*)malloc(s->size * sizeof(int));
s->top = push(s,12); // 4
s->top = push(s,13); // 3
s->top = push(s,14); // 2
s->top = push(s,15); // 1
s->top = push(s,16); // 0th element

show(s,s->top);
int var ;
var = peek(s,3);
// last in first out 
// printf("the var at top is %d",s->arr[s->top]);
// 0 - 16 1 -
printf("the var is %d",var);

  return 0;
}
