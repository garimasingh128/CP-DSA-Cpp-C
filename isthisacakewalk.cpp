#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=pow(10,(n-1)); i<=pow(10,n)-1;i++)
    {
        if(i%7==0 && i%3==0)
        {
		
        cout<<i;
        break;
    }
    }
    return 0;
}
