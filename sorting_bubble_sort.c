// sorting algorithms ///
// bubble sort ////
#include<stdio.h>
void traverse(int a[] , int size){
    for(int i = 0 ; i< size ; i++){
      printf("\n%d\t",a[i]);
    }
}
void bubblesort(int a[] , int size){
    int temp;
    for(int j = 0 ; j < size-1 ; j++){ // total no of passes 
      for(int i = 0 ; i< size-j-1 ; i++){  // total no of comparisions 
        if(a[i]>a[i+1]){
             temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
    }
    }    
}

int main()
{
int a[] = {12,54,65,7,23,9};
int n = 6;
traverse(a,n);
bubblesort(a,n);
traverse(a,n);

    return 0;
}
