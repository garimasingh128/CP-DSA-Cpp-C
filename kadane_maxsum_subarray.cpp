//Largest Sum Contiguous Subarray

#include<bits/stdc++.h>
using namespace std;

#define lli long long int

int main()
{
	//input array size
	int n;
	cout << "Enter array size: ";
	cin >> n;
	
	//input array
	int arr[n];
	cout << "Enter array elements: ";
	
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	
	//max sum subarray
	int max_end_here=0, max_so_far=0;
	
	for(int i=0; i<n; i++)
	{
		if( arr[i]>=0 && max_end_here<0 )
			max_end_here = 0;
			
		max_end_here += arr[i];
		if(max_so_far < max_end_here)
			max_so_far = max_end_here;
	}
	
	//output
	cout<<"Larges sum of subarray: " << max_so_far;
	
	return 0;
}
