#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define vll vector<ll>
#define ld long double
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define osetll tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ook order_of_key
#define fbo find_by_order
const int MOD=1000000007;
long long int inverse(long long int i){
    if(i==1) return 1;
    return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
ll POW(ll a,ll b)
{
    if(b==0) return 1;
    if(b==1) return a%MOD;
    ll temp=POW(a,b/2);
    if(b%2==0) return (temp*temp)%MOD;
    else return (((temp*temp)%MOD)*a)%MOD;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t,n,k,w,al,bl,cl,dl,ah,bh,ch,dh;
    fin>>t;
    for(int i=0;i<t;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        cin>>n>>k>>w;
        vll l(n),h(n),ans(n);
        for(int i=0;i<k;i++)
        {
            cin>>l[i];
        }
        cin>>al>>bl>>cl>>dl;
        for(int i=k;i<n;i++)
        {
            //l[i]=(al*l[i-2]+bl*l[i-1]+cl)%dl +1;
            l[i]=((l[i-2]%dl)*(al%dl))%dl;
            l[i]+=((l[i-1]%dl)*(bl%dl))%dl;
            l[i]%=dl;
            l[i]+=(cl%dl);
            l[i]%=dl;
            l[i]+=1;
        }
        for(int i=0;i<k;i++)
        {
            cin>>h[i];
        }
        cin>>ah>>bh>>ch>>dh;
        for(int i=k;i<n;i++)
        {
            h[i]=((h[i-2]%dh)*(ah%dh))%dh;
            h[i]+=((h[i-1]%dh)*(bh%dh))%dh;
            h[i]%=dh;
            h[i]+=(ch%dh);
            h[i]%=dh;
            h[i]+=1;
        }
        vll mx(20);
        ll en=l[0]+w;
        ans[0]=(((w+h[0])%MOD)*2)%MOD;
        set<ll> s;
        map<ll,ll> mp;
        if((l[0]+w)>=l[1])
        {
            s.insert(l[0]+w);
            mp[l[0]+w]=h[0];
        }
        for(int i=1;i<n;i++)
        {
            ans[i]=ans[i-1];
            if(l[i]<=en)
            {
                ans[i]+=(2*(l[i]+w-en))%MOD;
                ans[i]+=(2*h[i])%MOD;
                ll mx=0;
                if(!s.empty())
                {
                    for(set<ll>::iterator it=s.begin();it!=s.end();it++)
                    {
                        if( ((*it)>=l[i]) && ((*it)<=(l[i]+w)) )
                        mx=max(mx,mp[(*it)]);
                    }
                }
                ll temp=(min(mx,h[i])*2)%MOD;
                ans[i]=(ans[i]-temp+MOD)%MOD;
            }
            else
            {
                ans[i]+=(((w+h[i])%MOD)*2)%MOD;
                ans[i]%=MOD;
            }
            if(i!=(n-1))
            {
                if((l[i]+w)>=l[i+1])
                {
                    s.insert(l[i]+w);
                    mp[l[i]+w]=h[i];
                }
                if(!s.empty())
                {
                    vll v;
                    for(set<ll>::iterator it=s.begin();it!=s.end();it++)
                    {
                        ll temp=(*it);
                        if(temp<l[i+1])
                        {
                            v.PB(temp);
                            mp.erase(temp);
                        }
                    }
                    for(int i=0;i<v.size();i++)
                    {
                        s.erase(v[i]);
                    }
                }
            }

            en=l[i]+w;
        }
        ll k=1;
        for(int i=0;i<n;i++)
        {
            k*=ans[i];
            k%=MOD;
            //cout<<ans[i]<<" ";
        }
        cout<<k<<"\n";
    }
}
