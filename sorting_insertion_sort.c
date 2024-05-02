// sorting algorithms ///
// insertion sort //
#include<stdio.h>
void traverse(int a[] , int size){
    for(int i = 0 ; i< size ; i++){
      printf("%d\t",a[i]);
    }
    printf("\n");
}
void insertion(int a[] , int size){
    int key,j;
for(int i = 1 ; i< size ; i++){ // total no.of passes
    key = a[i];
    j = i-1;
    while(j>=0 && a[j]>key){
        a[j+1] = a[j];
        j--;
    }
    a[j+1] = key;
}
}
int main()
{
int s[] = {12,54,65,7,23,9};
// int s[]= {12,23,34,45,56,67};
int n = 6;
traverse(s,n);
insertion(s,n);
traverse(s,n);

    return 0;
}
