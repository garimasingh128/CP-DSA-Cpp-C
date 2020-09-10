#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int a[105];
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    int f1=1;
   // a[n+1]=a[0]=1<<30;
    int f=2;
    while(a[f]>a[f-1]) f++;
    while(a[f]==a[f-1]) f++;
    while(a[f]<a[f-1]) f++;
    if(f<=n) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
