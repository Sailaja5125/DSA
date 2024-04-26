#include<stdio.h>
#include<stdlib.h>

struct stack
{
   char *arr;
   int top ; 
   int size;
};
// stack top
int stacktop(struct stack *top){
    return top->arr[top->top];
}

// isEmpty
int isEmpty(struct stack *top){
    if (top->top == -1)
    {
        /* code */
        return 1;
    }
    return 0;
}
// isFull
int isFull(struct stack *top){
    if (top->top == top->size)
    {
        return 1;
    }
    return 0;
}
// push

void push(struct stack *top , char value){
    if (isFull(top))
    {
        /* code */
        printf("Stack overflow\n");
    }
    else
    {
        top->top++;
        top->arr[top->top] = value;
    }
}
// pop
char pop(struct stack *top){
    if (isFull(top))
    {
        /* code */
        printf("Stack overflow\n");
    }
    else
    {
        char value = top->arr[top->top] ;
        top->top--;
        return value;
    }
}
// isOperator
int isOperator(char ch){
    if (ch == '+'||ch == '-'||ch == '*'||ch == '/')
    {
        return 1;
    }
    return 0;
}
// precedence
int precedence(char ch){
 if (ch=='+'||ch=='-')
 {
    return 1;
 }
 else if (ch=='*'||ch=='/')
 {
    return 2;
 }
 else{
    return 0;
 }
}

// postfix
char *postfix(struct stack* top , char *ch){
   char* postfix =  (char *)malloc(top->size * sizeof(char));
   int j = 0 ;
   for (int i = 0; ch[i] != '\0'; i++)
   {
      if (!isOperator(ch[i]))
      {
         postfix[j] = ch[i] ;
         j++;
      }
      else
      {
         if (precedence(ch[i])>precedence(stacktop(top)))
         {
            push(top , ch[i]);
         }
         else
         {
            postfix[j] = pop(top);
            j++;
         }
      }
   }
//  add all the elements to postfix
while(!isEmpty(top)){
    postfix[j] = pop(top);
    j++;
}
postfix[j]='\0';
return postfix;
}

int main(){
 struct stack *s ;
 s->size = 7;
 s->top = -1;
 char *ch = "a-b+t/e";
 s->arr = (char *)malloc(s->size * sizeof(char));
 printf("duoah %s",postfix(s ,ch));
 

    return 0;
}
