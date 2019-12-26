#include<stdio.h>
int main()
{
int i,a[10],rem=0,sum=0;
printf("enter elements");
for(i=0;i<10;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<10;i++)
{
rem=a[i]%10;
if(rem==0)
{
sum=sum+a[i];
}
}
printf("sum of nos whose tenth place is divisible by 10 is %d",sum);
return 0;
}
