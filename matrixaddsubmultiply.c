#include<stdio.h>
int main()
{
int i,a[2][2],j,k,b[2][2],add[2][2],sub[2][2],mul[2][2],s=0;
printf("enter first matrix");
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("enter second matrix");
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
scanf("%d",&b[i][j]);
}
}
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
add[i][j]=a[i][j]+b[i][j];
sub[i][j]=a[i][j]-b[i][j];
}
}
printf("addition is \n");
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
printf("%d  ",add[i][j]);
}
printf("\n");
}
printf("subtraction is \n");
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
printf("%d  ",sub[i][j]);
}
printf("\n");
}
printf("multiply is \n");
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
s=0;
for(k=0;k<2;k++)
{
s=s+a[i][k]*b[k][j];
}
mul[i][j]=s;
}
}
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
printf("%d  ",mul[i][j]);
}
printf("\n");
}
return 0;
}
