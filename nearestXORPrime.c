#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
 
int* NearestXorPrime (int N) {
   // Write your code here
   int arr[4];
   long int i,a;
   int j;
   for(i=N+1;i<=100;i++)
   {
   	int c=0;
   	for(j=2;j<=i;j++)
   	{
   		if (i%j==0)
   		c++;
	   }
	   if(c<=2)
	   {
	   	break;
	   }
   }
   if(i^N<N)
   arr[0]=i;
   else
   arr[0]=-1;
   if(i^N>N)
   arr[1]=i;
   else
   arr[1]=-1;
   for(i=N+1;i<=1000000;i++)
   {
   	int c=0;
   	for(j=2;j<=i;j++)
   	{
   		if (i%j==0)
   		c++;
	   }
	   if(c>2)
	   {
	   	break;
	   }
   }
   if(i^N<N)
   arr[2]=i;
   else
   arr[2]=-1;
   if(i^N>N)
   arr[3]=i;
   else
   arr[3]=-1;
   return arr;
   
}
 
int main() {
    int T;
    scanf("%d", &T);
    int t_i,i_out_;
    for(t_i=0; t_i<T; t_i++)
    {
        int N;
        scanf("%d", &N);
        int* out_ = NearestXorPrime(N);
        for(i_out_=0; i_out_<4; i_out_++)
        	printf("%d ", out_[i_out_]);
        printf("\n");
    }
}
