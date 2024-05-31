// to find the cost of minimum spanning trees we use prim's algorithm 
//.>> its in greedy aproach
// take two arrays 
#include<stdio.h>
#include<limits.h>
// finds the minimum index 
int minKey(int cost[5] , int mstSet[5]){
    int min = INT_MAX ;
    int min_index;
    for (int  i = 0; i < 5; i++)
    {
        if (mstSet[i]== 0 && cost[i] < min) // should notbe visited and cost should be less than the maximum number i.e to get the minimum index and key{cost} for mst .
        {
            min = cost[i] ;
            min_index = i;
        }
        
    }
    
    return min_index; // the index of the min cost
}
 void printMST(int graph[5][5] , int parent[5]){
     printf("Edge \t Weight \n :");
     for(int i = 1 ; i< 5 ; i++){
        printf("%d -> %d \t %d \n",parent[i] , i , graph[i][parent[i]]);
     }
 }
 void primMst(int graph[5][5]){
    int parent[5]; // to store the mst;
    int cost[5]; // used to pick minimum weight edge 
    int mstSet[5] ; // represent set of vertices included in Mst
    for (int i = 0; i < 5; i++)
    {
        cost[i] = INT_MAX ; // defined as big number
        mstSet[i] = 0;
    }
    cost[0] = 0; // vertex picked as first vertex;
    parent[0] = -1;
 // MSt has 5-1 vertices
  for (int  i = 0; i < 4; i++)
  {
     int u = minKey(cost, mstSet);
     mstSet[u] = 1;
     for (int i = 0; i < 5; i++)
     {
        if (graph[u][i] && mstSet[i] == 0 && graph[u][i] < cost[i])
        {
            parent[i] = u; // index is placed in parent array
            cost[i] = graph[u][i];
        }
     }
  }
   printMST(graph , parent);
 }
int main(){
 int graph[5][5] = {   // connecting nodes  x-axis refers to the child nodes and y-axis refers to the parent i.e connecting node
  // 0 1 2 3 4 5 6
    {0,1,0,8,0}, // 0  is not connected to 0 but connected to one two three etc.
    {1,0,2,4,3}, // 1
    {0,2,0,0,7}, // 2
    {8,4,0,0,9}, // 3
    {0,3,7,9,0}, // 4

};
/* 0->1 = 2; ..1
   0->3 = 6; ..3

   1->0 = 2 
   1->2 = 3  ..2
   1->3 = 8 
   1->4 = 5  ..4

   2->1 = 3; 
   2->4 = 7; 

   3->0 = 6; 
   3->1 = 8;
   3->4 = 9;

   4->1 = 5; 
   4->2 = 7;
   4->3 = 9;

   
*/ 
 primMst(graph);


    return 0;
}