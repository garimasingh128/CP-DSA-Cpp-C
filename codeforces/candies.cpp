#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    double n;
    long long int ans;
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        ans=ceil((n/2)-1);
        cout<<ans<<endl;
    }
    return 0;
}
