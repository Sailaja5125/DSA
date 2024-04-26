#include<stdio.h>
#define s 10

void insert_at_index(int arr[s],int num ,int index, int size){
for(int i = size ; i>=index ; i--){   
    arr[i+1] = arr[i];
    // logic 
    /*a[4] = a[4+1]
      a[3] = a[3+1]
      a[2] = a[2+1]
      a[1] = a[1+1]
      // index given is 0 
      a[0] = a[0+1]
      at a[index=0] = num*/
}
arr[index] = num;
}
void main(){
    int arr[s] = {12,23,34,45,56};
    int size = 6;
insert_at_index(arr,67,5,size);
insert_at_index(arr,78,6,size);

size++;
for(int i = 0 ; i<size ; i++){
   printf("%d\t",arr[i]);
}
}
