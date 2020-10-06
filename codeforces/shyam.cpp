#include <cmath>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        stack<char> st;
        int c=0;
        for(int i=0;i<(int)s.length();i++)
        {
            if(s[i]=='<')
                st.push(s[i]);
            if(s[i]=='>' && st.top()=='<')
            {
                st.pop();
                c=c+2;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
