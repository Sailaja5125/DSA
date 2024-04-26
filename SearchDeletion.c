#include<stdio.h>
int delete_element(int a[10], int size , int element){
      int index = -1 ; 
      // search the element using search 
      for(int i =0 ; i< size ;i++){
            if(a[i]==element){
                  index = i;
                  break;
            }
      }
      if(index!=-1){
            for(int i = index ; i< size ; i++){
                  a[i] = a[i+1];
            }
      }
    else{
                  printf("element not found");
        }
      return index;
}

void main(){
 int arr[10] = {12,23,34,45,56};
 int size = 5;
 int x = delete_element(arr,size,56);
 size--;
 for(int i = 0 ; i<size ; i++){
      printf("%d\t",arr[i]);
 } 
 printf("\nthe deleted element is in the index %d",x);
}
