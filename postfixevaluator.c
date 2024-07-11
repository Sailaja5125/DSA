#include<stdio.h>
#include<string.h>

#define S 50

int s[S]; // stack array
char post[S]; // expression array
int top = -1;

void push(int val) {
    if (top >= S - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    s[top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int val = s[top];
    top--;
    return val;
}

void calculator(char c) {
    int a, b, ans;
    a = pop();
    b = pop();
    
    switch(c) {
        case '+':
            ans = b + a;
            break;
        case '-':
            ans = b - a;
            break;
        case '*':
            ans = b * a;
            break;
        case '/':
            if (a == 0) {
                printf("Division by zero error\n");
                return;
            }
            ans = b / a;
            break;
        default:
            printf("Invalid operator\n");
            return;
    }
    
    push(ans);
}

int main() {
    int i = 0;
    printf("Enter a postfix expression: ");
    scanf("%s", post);
    
    while (post[i] != '\0') {
        if (post[i] >= '0' && post[i] <= '9') {
            push(post[i] - '0'); // Convert character digit to integer
        } else if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/') {
            calculator(post[i]);
        } else {
            printf("Invalid character in postfix expression: %c\n", post[i]);
            return 1;
        }
        i++;
    }
    
    if (top == 0) {
        printf("Result: %d\n", s[top]);
    } else {
        printf("Invalid postfix expression\n");
    }
    
    return 0;
}

