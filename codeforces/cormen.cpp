#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,k,i,cnt=0,a[1000],x;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=1;i<n;i++){
        x=a[i];
        if(a[i]+a[i-1]<k){
            a[i]=k-a[i-1];
            cnt+=a[i]-x;

        }
    }
    cout<<cnt<<endl;
    for(i=0;i<n-1;i++)
        cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
    return 0;
}
