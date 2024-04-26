#include<stdio.h>
#define s 10
int delete_at_index(int arr[s] , int size , int index){
        int d = arr[index]; 
        if(index>size){
             return -1;
        }
        else{
    for(int i = index ; i<size ; i++){
            arr[i] = arr[i+1];
            // logic
            /*a[1] = a[1]
            at index = 2
              a[2] = a[2+1]
              a[3] = a[3+1]
              a[4] = a[4+1]
              a[5] = a[5+1]*/
    }
       return d;
    }
}
void main(){
    int arr[s] = {12,23,34,45,56};
    int size = 5;
    int x = delete_at_index(arr,size,4);

    size--;

for(int i = 0 ; i<size ; i++){
   printf("%d\t",arr[i]);
}
printf("the element deleted is %d",x);
}
