#include<stdio.h>
#include<stdlib.h>
int f(int i){
   i++;
}
int main(void)
{

  int t[] = {8 , 4 , 2 , 1};
  int *p = (int *)malloc(sizeof(t));
  int i ;

  for(i = 0 ; i<4 ; i++){
    p[3-i] = t[i];
  }
  printf("%d",*(p+2));
  free(p);
return 0;
}