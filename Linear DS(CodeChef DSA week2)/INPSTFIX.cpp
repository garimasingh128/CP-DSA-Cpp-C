//https://www.codechef.com/LRNDSA02/problems/INPSTFIX
#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
typedef long long ll;

int is_op( char a ){
	if( a=='+'||a=='-'||a=='*'||a=='/'||a=='^' )
		return 1;
	else 
		return 0;
}
int precedence( char a ){
	if( a=='^' )
		return 3;
	else if( a=='/'||a=='*' )
		return 2;
	else if ( a=='+'||a=='-' )
		return 1;
}

int main(){
	int t;
	cin >> t;
	while( t-- ){
		int n;
		cin >> n;
		string s;
		cin >> s;
		//operand -> print
		//operator -> (higher precedence/empty stack/ '(' in stack) push to stack
		//operator -> (pop all operators b4 encountering '('/  lower precedence/ empty -> then push)
		//'(' -> push
		//')' -> pop until encountering '('
		stack < char > i2p;
		for(int i=0; i<n; i++){
			if(is_op(s[i])){
					if(!i2p.empty()){
						if(i2p.top()=='(')
							i2p.push(s[i]);
						else if(precedence(i2p.top()) < precedence(s[i]))
							i2p.push(s[i]);
						else{
							while((!i2p.empty())&&(i2p.top()!='(')&&(precedence(i2p.top()) >= precedence(s[i]))){
								cout << i2p.top();
								i2p.pop();
						}
						i2p.push(s[i]);
					}
				}
				else
					i2p.push(s[i]);
			}
			else{
				if(s[i]=='('){
					i2p.push(s[i]);
				}
				else if(s[i]==')'){
					while(i2p.top()!='('){
						cout << i2p.top();
						i2p.pop();
					}
					i2p.pop();
				}
				else
					cout << s[i];
			}
		}
		while(!i2p.empty()){
			cout << i2p.top();
			i2p.pop();
		}
		cout << '\n';
	}
}