#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define scl1(a)             scanf("%lld", &a);


int main()
{
    ll i,j=0,k,l,a=0,b,m,n,ck=0,aa,bb,dk=0;

    scl1(n);

    while(n!=0){
        if(n>=100){
            n-=100;
            ck++;
        }
        else if(n>=20){
            n-=20;
            ck++;
        }
        else if(n>=10){
            n-=10;
            ck++;
        }
        else if(n>=5){
            n-=5;
            ck++;
        }
        else if(n>=1){
            n-=1;
            ck++;
        }
    }
    cout<<ck<<endl;
}

