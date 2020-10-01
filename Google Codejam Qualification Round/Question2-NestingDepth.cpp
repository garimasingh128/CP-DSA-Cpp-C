#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int k = 1; k<= t ; k++)
    {
        char s[100] , ans[3000];
        cin >> s;
        char prev = '0';
        int j = 0;
        for( int i= 0 ; i<strlen(s) ; i++)
        {
            if( s[i] > prev )
            {
                j = j - prev + 48;
                for(char a = prev ; a<s[i] ; a++)
                    ans[j++] = '(';
                ans[j++] = s[i];
                for(int a ='0' ; a<s[i];a++)
                    ans[j++] = ')';
            }
            else if( s[i] < prev && s[i] != '0')
            {
                ans[j++] = ')';
                ans[j-1-s[i]+48] = s[i];
            }
            else if(s[i] == prev && s[i] != '0')
            {
                ans[j++] = ')';
                ans[j-1-s[i]+48] = s[i];
            }
            else if(s[i] == '0')
            {
                ans[j++] = s[i];
            }
            prev = s[i];
        }

            ans[j] = '\0';
            cout <<"Case #"<<k<<": "<< ans <<"\n";
    }
}
