#include<stdio.h>
int main()
{
  int a[10] , size = 5 , max1,max2,max3;
  printf("enter %d numbers",size);
  for(int i = 0 ; i< size ; i++)
  {
    scanf("%d",&a[i]);
     max1=max2=a[0];
  }
   for(int i = 0 ; i<size ; i++)
   {
      if(a[i]>max1)
      {  
      max2 = max1;
      max1 = a[i];
      }
      else if(a[i]>max2 && a[i]!= max1)
      {
        max2 = a[i];
      }
   }
      printf("the second largest element in the array %d\t",max2);

  return 0;
}
