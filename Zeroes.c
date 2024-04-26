#include<stdio.h>
int main()
{
  int a[10] , size = 5 , max1,max2,max3;
  for(int i = 0 ; i< size ; i++)
  {
    scanf("%d",&a[i]);
  }
  // printf all zeroes to the corner of the array
  for(int i = 0 ; i< size ; i++)
  {
    if(a[i] == 0)
    {
      a[i]=a[i+1];  // delete the element at 0th palce and place it at the las
       a[i+1] = a[size-1]; 
       a[size-1]=0;
    }
    
  printf("%d\t",a[i]);
  }
  
  return 0;

}
