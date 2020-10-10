#include<bits/stdc++.h>
using namespace  std;
int main()
{
int a[4],ar,b,c,i;
while(cin>>a[0]>>a[1]>>a[2]>>a[3])
{
   sort(a,a+4);
   ar=a[3]-a[0];
   b=a[3]-a[2];
   c=a[3]-a[1];
   cout<<ar<<" "<<b<<" "<<c<<endl;

}

}
