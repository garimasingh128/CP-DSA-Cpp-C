#include<bits/stdc++.h>
#include<cmath>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int m=1;m<=t;m++)
    {
        int n,q,d,s=0;
        cin>>n>>q;
        vector<int> arr(n);
        vector<int> arr2(n);
        for(int i=0;i<n;i++)
        {
            cin>>d;
            arr.push_back(d);
        }
        for(int j=1;j<=q;j++)
        {
            char o[1];
            char oc[]="U";
            int a,b,l;
            cin>>o;
            cin>>a>>b;
            if(strcmp(o,oc)==0)
            {
                for(l=0;l<a-1;l++)
                {
                    arr2.push_back(arr.at(l));
                }
                auto it = arr2.insert(arr2.begin() + a - 1, b);
                for(l=a;l<n;l++)
                {
                    arr2.push_back(arr.at(l));
                }
            }
            if(strcmp(o,oc)!=0)
            {
                for(l=a-1;l<b-1;l++)
                {
                    if(arr2.empty())
                    {
                        s=s+(int)(pow((-1), (l+1-a))+0.5)*arr.at(l)*(l+2-a);
                    }
                    else{
                        s=s+(int)(pow((-1), (l+1-a))+0.5)*arr2.at(l)*(l+2-a);
                    }
                }
                
            }
        }
        cout<<"Case #"<<m<<": "<<s<<endl;
    }
}
