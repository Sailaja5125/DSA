#include<stdio.h>
#include<stdlib.h>
// dfs is implemented by stacks.
// bfs is implemented by queues.
int visited[7] = {0,0,0,0,0,0,0}; // initialy the nodes arent visited 
int  a[7][7] = {   // connecting nodes  x-axis refers to the child nodes and y-axis refers to the parent i.e connecting node
  // 0 1 2 3 4 5 6
    {0,1,1,1,0,0,0}, // 0  is not connected to 0 but connected to one two three etc.
    {1,0,1,0,0,0,0}, // 1
    {1,1,0,1,1,0,0}, // 2
    {1,0,1,0,1,0,0}, // 3
    {0,0,1,1,0,1,1}, // 4
    {0,0,0,0,1,0,0}, // 5
    {0,0,0,0,1,0,0}, // 6
};

void DFS(int x){  // starting node is given
    
    printf("%d\t",x); // starting node is printed
    visited[x] = 1;  // its visited value is 1 
    for (int j = 0; j < 7; j++)  
    {
        if (a[x][j]==1 && visited[j]==0) // checking if a[0][0 to 7] == 1 && visited[0 to 7] == 0 if yes recursively call visited for j  
        {
            DFS(j);  // pushing j into stack
        }
                
    }
    
}
int main(){

 DFS(1);  // starting node is given

    return 0;
}