#include<stdio.h>
int main()
{
int i,a[10],max,min;
printf("enter elements");
for(i=0;i<10;i++)
{
scanf("%d",&a[i]);
}
max=a[0];
min=a[0];
for(i=1;i<10;i++)
{
if(a[i]>max)
max=a[i];
if(a[i]<min)
min=a[i];
}
printf("%d is maximum no",max);
printf("%d is minimum no",min);
return 0;
}
