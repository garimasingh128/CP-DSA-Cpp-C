#include<stdio.h>
int main()
{
int n,i,p,m,j;
printf("enter total elements in array \n");
scanf("%d",&n);
int a[n];
printf("enter elements of array \n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("enter element to insert and position \n");
scanf("%d %d",&m,&p);
for(i=n+1;i>=p;i--)
{
a[i]=a[i-1];
}
a[p-1]=m;
printf("after insertion array is \n");
for(i=0;i<=n;i++)
{
printf("%d \n",a[i]);
}
printf("enter element to delete \n");
scanf("%d",&m);
for(i=0;i<n;i++)
{
if(a[i]==m)
break;
}
for(j=i+1;j<=n;j++)
{
a[j-1]=a[j];
}
printf("after deletion array is \n");
for(i=0;i<n;i++)
{
printf("%d \n",a[i]);
}
return 0;
}

