    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define ll long long
    #define MOD 1000000007
     
     
    int main()
    {
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
        string s;
        cin>>s;
        ll ans=0;
        ll n=s.length();
        ll l[n]={0};
        ll total=0;
        
        for(ll i=2;i<n-2;i++){
            if(s[i-2]=='v' && s[i-1]=='v')
                l[i]=l[i-1]+1;
            else
                l[i]=l[i-1];
        }
        
        for(ll i=0;i<n-1;i++)
            if(s[i]=='v' && s[i+1]=='v')
                total++;
                
        
        for(ll i=2;i<n-2;i++){
            if(s[i]=='o')
                ans+=l[i]*(total-l[i]);
        }
        cout<<ans;
        
        return 0;
    }
