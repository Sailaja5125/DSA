#include<stdio.h>
int main()
{
  int a[10] , size = 5 , max1,max2,max3;
  for(int i = 0 ; i< size ; i++)
  {
    scanf("%d",&a[i]);
     max1= max2 =max3= a[0];
  }
   for(int i = 0 ; i<size ; i++)
   {
      if(a[i]>max1)
      {  
      max3 = max2;
      max2 = max1;
      max1 = a[i];
      }
      else if(a[i]>max2 && a[i]!= max1)
      {
        max3 = max2;
        max2 = a[i];
      }
      else if(a[i]>max3 && a[i]!= max2 && a[i]!=max1)
      {
        max3 = a[i];
      }
   }
      printf("%d\t %d\t %d\t",max1,max2,max3);

  return 0;
}
