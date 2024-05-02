#include<stdio.h>
#include<stdlib.h>
struct q{
  int size;
  int front;
  int rare;
  int *arr;
};
// isEmpty
int isEmpty(struct q *que){
    if(que->rare== -1 ){
     return 1;
    }
    return 0;
}
// is Full
int isFull(struct q *que){
    if(que->rare == que->size){
     return 1;
    }
    return 0;
}
// Enque 
int Enque(struct q *que , int value){
    if (isFull(que))
    {
        printf("queue overflow\n");
    }
    else
    {
        que->rare++;
         que->arr[que->rare] = value;        
         return  que->arr[que->rare];
    }
}
// deque
int Deque(struct q *que){
    if (isEmpty(que))
    {
        printf("queue underflow\n");
    }
    else{
        que->front++;
        que->rare--;
        int value = que->arr[que->front];
        return value;
    }
}
// traverse
void traverse(struct q *que){
 if (isEmpty(que))
 {
    printf("queue is underflow\n");
 }
  else{
    for (int i = que->rare; i >= 0 ; i--)
    {
        printf("%d\t",que->arr[i]);
    }    
}
}

int main(){
 struct q que ;
 que.front = que.rare = -1;
 que.size = 20;
 que.arr = (int *)malloc(que.size * sizeof(int));

// breadth first search
int u ; 
int i = 1 ; 
int visited[7] = {0,0,0,0,0,0,0}; // initialy the nodes arent visited 
int  a[7][7] = {
  // 0 1 2 3 4 5 6
    {0,1,1,1,0,0,0}, // 0
    {1,0,1,0,0,0,0}, // 1
    {1,1,0,1,1,0,0}, // 2
    {1,0,1,0,1,0,0}, // 3
    {0,0,1,1,0,1,1}, // 4
    {0,0,0,0,1,0,0}, // 5
    {0,0,0,0,1,0,0}, // 6
};
printf("%d",i);
visited[i] = 1;
Enque(&que , i); // enque i for exploration 
while (!isEmpty(&que))
{
    int node = Deque(&que);
    for (int  j = 0; j < 6; j++)
    {
        if (a[node][j] == 1 && visited[j]==0)
        {
           printf("%d",j);
           visited[j] = 1;
           Enque(&que , j); 
        }
        
    }
    
}


    return 0;
}
