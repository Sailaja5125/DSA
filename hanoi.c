#include<stdio.h>

void hanoi(char , char , char, int);

void main(){
	int num;
	printf("\n enter number of disks");
	scanf("%d",&num);
	printf("\n tower of hanoi for %d number of disks \n",num);
	
	hanoi('A','B','C',num); // towers of hanoi for A>B>C are towers
	
}
// using recursive approach
void hanoi(char from , char to , char other , int n){
	if(n<=0) // there should be no disks
	   printf("illegal no of disks");
	if(n==1) // if n==1
	   printf("Move the disks from %c to %c\n",from ,other);
	if(n>1){
		hanoi(from , other , to , n-1); 
		hanoi(from , to , other , 1);
		hanoi(to , from, other , n-1);
	}
	// tutorial yt.
}
