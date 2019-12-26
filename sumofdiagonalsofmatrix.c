#include<stdio.h>
int main()
{
int i,j,a[3][3],sumrl=0,sumlr=0;
printf("enter matrix of size 3X3");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
scanf("%d",&a[i][j]);
}
}
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
if(i==j)
sumlr=sumlr+a[i][j];
if(i+j==2)
sumrl=sumrl+a[i][j];
}
}
printf("sum of diagonal elements from left to right is %d \n",sumlr);
printf("sum of diagonal elements from right to left is %d",sumrl);
return 0;
}
