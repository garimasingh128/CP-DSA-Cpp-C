/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include <bits/stdc++.h> 
#include <list> 
using namespace std;
int main()
{
	//Write code here
	long int t;
	cin>>t;
	for(long int j=0; j<t; j++)
	{
		long int n;
		cin>>n;
		list<long int> arr1;
		list<long int> arr2;
		long int p;
		for(long int i=0;i<n;i++)
		{
			cin>>p;
			arr1.push_back(p);
		}
		cout<<"hello";
		for(long int i=0;i<n;i++)
		{
			cin>>p;
			arr2.push_back(p);
		}
		cout<<"hello";
		arr1.sort();
		//cout<<arr1;
		arr2.sort();
		//cout<<arr2;
		long int c=0;
		long int a=0, b=0;
		cout<<"hello /n";
		long int len = arr1.size();
		while(len!=0)
		{
			if (arr1.front() > arr2.front())  
			{
                c=c+1;  
                arr1.pop_front();
                arr2.pop_front();
                len--;
			}
            else
            {
                arr2.pop_front();
			}
			
        }
		cout<<c;
	}
}

 
