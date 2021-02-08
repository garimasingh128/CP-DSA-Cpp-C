/* The famous problem of checking Paranthesis is 'Balanced' or 'Not Balanced' using stacks. 
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” 
and 'not balanced' for exp = “[(])”
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;cin>>t;
	while(t--)
	{
	    string n;
		cin>>n;
	    stack<int>s;
		int flag=0;
	    for(int i=0;i<n.length();i++)
	    {
	    	/* While traversing the string if found symbols like '(', '{' and '[' push them in stack*/
	        if(n[i]=='(' || n[i]=='{' || n[i]=='[')
	        s.push(n[i]);
	        else
	        { 
	        /* If string starts with ')', '}, or ']', then the string can never be balances, so raise the flag*/
			if(s.empty())
	        {
	            flag=1;
	            break;
	        }
	        else if(n[i]==')')
	        {
	        	/* If string starts with ')' then the top of the stack must contain '(' for the string to be valid.
				Pop the top of stack.
				*/
	            int t=s.top();
	            s.pop();
	            if(t!='(')
	            {
	                flag=1;break;
	            }
	        }   
	        else if(n[i]=='}')
	        {
	        		/* If string starts with '}' then the top of the stack must contain '(' for the string to be valid.
				Pop the top of stack.
				*/
	            int t=s.top();
	            s.pop();
	            if(t!='{')
	            {
	                flag=1;break;
	            }
	        }
	         else if(n[i]==']')
	        {
	        		/* If string starts with ']' then the top of the stack must contain '(' for the string to be valid.
				Pop the top of stack.
				*/
	            int t=s.top();
	            s.pop();
	            if(t!='[')
	            {
	                flag=1;break;
	            }
	        }
	        }
	    }
	    	/* If at last the stack is empty and the flag value is also 1, then it is balanced else unbalanced.
				*/
	    if(flag==0 && s.empty())
	    cout<<"balanced\n";
	    else
	    cout<<"not balanced\n";
	}
}
