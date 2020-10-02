
#include<bits/stdc++.h> 
#include<limits> 
using namespace std; 
  
int maxSubArraySum(int A[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0;
  
    for (int i=0; i< size; i++ ) 
    { 
        max_ending_here += A[i]; // Maximum Local Sum
  
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here;  // Maximum Global Sum
        
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far;
} 
  
int main() 
{ 
    int n; // Size of the array
    cin>>n;

    int A[n];

    for(int i=0;i<n;i++)
        cin>>A[i];

    int answer = maxSubArraySum(A, n); 

    cout<<answer<<endl;

    return 0; 
} 
