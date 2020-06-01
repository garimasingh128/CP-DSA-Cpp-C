// CPP implementation of the approach 

#include <bits/stdc++.h> 
#include<unordered_set>
using namespace std; 


// Function to return an ArrayList containing 
// all the perfect squares upto n 
vector<int> getPerfectSquares(int n) 
{ 
	vector<int> perfectSquares; 
	int current = 1, i = 1; 

	// while current perfect square is less than or equal to n 
	while (current <= n) 
	{ 
		perfectSquares.push_back(current); 
		current = static_cast<int>(pow(++i, 2)); 
	} 
	return perfectSquares; 
} 

// Function to print the sum of maximum 
// two elements from the array 
int maxPairSum(vector<int> &arr) 
{ 
	int n = arr.size(); 
	int max, secondMax; 
	if (arr[0] > arr[1]) 
	{ 
		max = arr[0]; 
		secondMax = arr[1]; 
	} 
	else
	{ 
		max = arr[1]; 
		secondMax = arr[0]; 
	} 

	for (int i = 2; i < n; i++) 
	{ 
		if (arr[i] > max) 
		{ 
			secondMax = max; 
			max = arr[i]; 
		} 
		else if (arr[i] > secondMax) 
		{ 
			secondMax = arr[i]; 
		} 
	} 
	return (max + secondMax); 
} 

// Function to return the count of numbers that 
// when added with n give a perfect square 
int countPairsWith(int n, vector<int> &perfectSquares, unordered_set<int> &nums) 
{ 
	int count = 0; 
	for (int i = 0; i < perfectSquares.size(); i++) 
	{ 
		int temp = perfectSquares[i] - n; 

		// temp > n is checked so that pairs 
		// (x, y) and (y, x) don't get counted twice 
		if (temp > n && find(nums.begin(), nums.end(), temp) != nums.end()) 
		{ 
			count++; 
		} 
	} 
	return count; 
} 

// Function to count the pairs whose sum is a perfect square 
int countPairs(vector<int> &arr) 
{ 
	int i, n = arr.size(); 

	// Sum of the maximum two elements from the array 
	int max = maxPairSum(arr); 

	// List of perfect squares upto max 
	vector<int> perfectSquares = getPerfectSquares(max); 

	// Contains all the array elements 
	unordered_set<int> nums; 
	for (i = 0; i < n; i++) 
	{ 
		nums.insert(arr[i]); 
	} 

	int count = 0; 
	for (i = 0; i < n; i++) 
	{ 

		// Add count of the elements that when 
		// added with arr[i] give a perfect square 
		count += countPairsWith(arr[i], perfectSquares, nums); 
	} 
	return count; 
} 

// Driver code 
int main() 
{ 


    int t;
    cin>>t;
    for(int m=1;m<=t;m++)
    { 
        long int n;
        cin>>n;
        int d;
    vector<int> arr; 
    for(int i=0;i<n;i++)
        {
            cin>>d;
            arr.push_back(d);
        }
	cout <<"Case #"<<m<<": "<<countPairs(arr)<< endl; 
    }
	return 0; 
} 

