// sorting algorithms ///
//// bubble sort ////
#include<stdio.h>
void traverse(int a[] , int size){
    for(int i = 0 ; i< size ; i++){
      printf("%d\t",a[i]);
    }
    printf("\n");
}
int partition(int a[] , int low , int high){
  int pivot ,i , j;
  pivot = a[low];
   i = low+1;
   j = high;
   int temp;
   do{
  while(a[i]<=pivot){
    i++;
   }  
  while(a[j]>pivot){
    j--;
   }  
   if(i<j){ 
    temp = a[i] ; 
    a[i] = a[j] ; 
    a[j] = temp;
   }
   }
   while(i<j);
  // swap a[low] = a[j] 
    temp = a[low] ; 
    a[low] = a[j] ; 
    a[j] = temp;
    return j; 
}
void quicksort(int a[] , int low , int high){
int partionindex ; 
if(low<high){
  partionindex = partition(a , low , high);
  quicksort(a,low,partionindex-1); // sort left subarray
  quicksort(a,partionindex+1 ,high);  //sort right sunb array
}
}

int main()
{
int s[] = {12,54,65,7,23,9};
// int s[]= {12,23,34,45,56,67};
int n = 6;
traverse(s,n);
quicksort(s,0,n-1);
traverse(s,n);

    return 0;
}
