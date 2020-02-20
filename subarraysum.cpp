
#include <iostream> 
using namespace std; 

int subArraySum(int arr[], int n, int sum) 
{ 
	int curr_sum = arr[0], start = 0, i; 

	for (i = 1; i <= n; i++) 
	{ 
		while (curr_sum > sum && start < i) 
		{ 
			curr_sum = curr_sum - arr[start]; 
			start++; 
		} 
		if (curr_sum == sum) 
		{ 
		for(int j=start;j<=i-1;j++)
		{
			cout<<arr[j]<<" ";
		}
		cout<<endl;	
		} 
		if (i < n) 
		curr_sum = curr_sum + arr[i]; 
	}
		
} 

int main() 
{ 
	int arr[] = {1,2,3,4,5,6,7,8,9}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int sum = 6; 
	subArraySum(arr, n, sum); 
	return 0; 
} 

