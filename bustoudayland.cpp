#include <bits/stdc++.h>

using namespace std;

int main(){ 
  int t;
  cin>>t;
   int m=5; int n=t;
   char mat[n][m];
   for(int i=0;i<n;i++)
   {
   	for(int j=0;j<m;j++)
   	{
   		cin>>mat[i][j];
	   }
   }
   int c=0;
   for(int i=0;i<n;i++)
   {
   if(mat[i][0]=='O' && mat[i][1]=='O')
   {
   	mat[i][0]='+';
   	mat[i][1]='+';
   	c=1;
   	break;
   }
     if(mat[i][3]=='O' && mat[i][4]=='O')
   {
   	mat[i][3]='+';
   	mat[i][4]='+';
   	c=1;
   	break;
   }
}
if(c==1)
{
	cout<<"YES"<<endl;
}
else {
	cout<<"NO"<<endl;
	return 0;
}
for(int i=0;i<n;i++)
   {
   	for(int j=0;j<m;j++)
   	{
   	cout<<mat[i][j];	
}
cout<<endl;
}
    return 0;
}
