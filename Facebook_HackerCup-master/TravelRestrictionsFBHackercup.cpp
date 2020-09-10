//take input of number of airlines:
//for each air line :
//take 3 input:
//countries,string1,string2
//counter=1
//loop1( condition (i in)-length of string1):
//nexted loop2(condition- i to length of string)
//if (i==j){
//a[i][j]="Y"}
//else{
//if(string2[i]==''Y'' string1[j]=="Y"and counter==1):
//a[i][j]="Y"
//print(a[i][j], end ='''')
//else:
//a[i][j]="N"
//counter-=1
//print(a[i][j],end='''')}
//after completion of loop 2 chng line

//5
//2
//YY
//YY
//2
//NY
//YY
//2
//NN
//YY
//5
//YNNYY
//YYYNY
//10
//NYYYNNYYYY
//YYNYYNYYNY

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	while(n--)
	{
		int c;
		cin>>c;
		char a[c][c];
		string string1, string2;
		cin>>string1;
		cin>>string2;
		int counter=1;
		for(int i=0;i<string1.length();i++)
		{
			for(int j=0;j<string2.length() ; j++)
			{
			if(i==j)
			{
			a[i][j]='Y';	
			}	
			else {
				if(string2[i]=='Y' && string1[j]=='Y' && counter==1)
				{
					a[i][j]='Y';
					cout<<a[i][j]<<" ";
				}
				else {
					a[i][j]='N';
					counter--;
					cout<<a[i][j]<<" ";
				}
			}
			}
			cout<<"/n";
			
		}
	}
	return 0;
}
