#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int l;
        int bull=0, cow=0;
        cin>>l;
        string w1, w2;
        getline (cin, w1);
        cout<<"hi";
        getline (cin, w2);
        cout<<"hi";
        for(int j=0; j<l;j++)
        {
            if(w1[j]==w2[j])
            {
                bull++;
           w1.erase(std::remove(w1.begin(), w1.end(), w1[j]), w1.end());
                 w2.erase(std::remove(w2.begin(), w2.end(), w2[j]), w2.end());
            }
            
        }
        
        for(int j=0;j<(int)w2.length();j++)
        {
            for(int k=0;k<(int)w1.length();k++)
            {
                if(w1[k]==w2[i])
                    cow++;
            }
        }
        cout<<bull<<endl<<cow<<endl;
    }
    return 0;
}
