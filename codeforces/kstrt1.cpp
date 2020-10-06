#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int m=1;m<=t;m++)
    {
        int n,k,d,c1=0;
        vector<int> ar(n);
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>d;
            ar.push_back(d);
        }
        for (int i=0;i<n;i++)
        {
            if(ar.at(i)==k)
            {
                for(int j=0;j<k;j++)
                {
                    if(ar.at(i+j)==k-j)
                    {
                        c1++;
                    }
                }
            }
        }
        cout<<"Case #"<<m<<": "<<c1/k<<endl;
    }
}
