// sorting algorithms ///
//// merge sort ////
#include<stdio.h>
void traverse(int a[] , int size){
    for(int i = 0 ; i< size ; i++){
      printf("%d\t",a[i]);
    }
    printf("\n");
}
void merge(int a[] ,int mid ,int low , int high ){
  int i , j, k ,b[high+1];
  i = low;
  j = mid+1;
  k = low;
  while(i<=mid && j<=high){
    if(a[i]<a[j]){
      b[k] = a[i];
      i++;
      k++;
    }
    else{
      b[k] = a[j];
      j++;
      k++;
    }
  }
    while(i<=mid){
      b[k] = a[i];
      k++;
      i++;
    }
    while(j<=high){
      b[k] = a[j];
      k++;
      j++;
    }
    for(int i = low ; i<=high ; i++){
      a[i] = b[i];
    }
  }
  void mergesort(int a[] , int low , int high){
    int mid ; 
    if(low < high){
      mid = (low+high)/2;
      mergesort(a,low,mid);
      mergesort(a,mid+1,high);
      merge(a,mid,low,high);
    }
  }
int main()
{
int s[] = {12,54,65,7,23,9};
int n = 6;
traverse(s,n);
mergesort(s,0,6);
traverse(s,n);

  return 0;
}
