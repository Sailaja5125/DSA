#include<stdio.h>
int search_element(int arr[] ,int size, int element){
      int low = 0 ;
      int high = size-1; 
      while(low<=high){
           int mid = (low+high)/2;
            if(arr[mid]==element){
                  return mid;
            }
            else if(arr[mid]>element){
                  high = mid-1;
            }
            else{
                  low = mid+1;
            }
      }
      return -1; // element is not present
}
// delete the element 
void delete_element(int a[], int size, int index){
      for(int i = index ; i<size ; i++){
            a[i]= a[i+1];
      }
}
void main(){
   int arr[10] = {2,4,6,8,10,12,14,16,18,20};
   int size = sizeof(arr)/sizeof(int);
   int element ; 
   printf("enter the element you wanna delete");
   scanf("%d",&element);
   int x = search_element(arr,size,element); // x is the index which is being returned
   if(x==-1){
      printf("element is not found");
   }
   else{
      printf("the element is found in the index %d",x);
   }
    delete_element(arr,size,x);
   size--;
   printf("the element %d has been deleted\n",element);
   for(int i =0 ; i< size ; i++){
      printf("%d\t",arr[i]);
   }
}
