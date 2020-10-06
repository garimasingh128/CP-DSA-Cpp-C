#include<iostream>
using namespace std;

int main()
{

    int i,t,c=0,ar[101],c1=0;
    while(cin>>t)
    {
        for(i=0; i<t; i++)
        {
            cin>>ar[i];
            if(ar[i]==0)
                c++;
            else if(ar[i]==1)
                c1++;
        }
        if(c1>=1)
            cout<<"HARD"<<endl;
        else
            cout<<"EASY"<<endl;
            c1=0,c=0;
    }
}
