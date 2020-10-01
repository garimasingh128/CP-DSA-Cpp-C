#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n1,n2,n3,i,j;
    cin>>n1>>n2>>n3;
 long long  int a[n1],b[n2],c[n3];
   long long int x=0,y=0,z=0;
    for(i=0;i<n1;i++)
    {
        cin>>a[i];
        x=x+a[i];
    }
    for(i=0;i<n2;i++)
    {
        cin>>b[i];
        y=y+b[i];
    }
    for(i=0;i<n3;i++)
    {
        cin>>c[i];
        z=z+c[i];
    }
   long long int p=0,q=0,r=0;
    while(x!=y || y!=z || x!=z)
    {
        if(x>y || x>z)
        x=x-a[p++];
        if(y>x || y>z)
        y=y-b[q++];
        if(z>x || z>y)
        z=z-c[r++];
    }
    cout<<y;
}

