#include <bits/stdc++.h> 
using namespace std; 
  
// Function to display the array 
void display(int a[], int n) 
{ 
    for (int i = 0; i < n; i++) { 
        cout << a[i] << "  "; 
    } 
    cout << endl; 
} 
  
// Function to find the permutations 
void findPermutations(int a[], int n) 
{ 
  
    // Sort the given array 
    sort(a, a + n); 
  
    // Find all possible permutations 
    cout << "Possible permutations are:\n"; 
    do { 
        display(a, n); 
    } while (next_permutation(a, a + n)); 
} 
  
// Driver code 
int main() 
{ 
      int t,n,i;
      cin>>t;
      while(t--)
      {
          cin>>n;
          int a[n];
          for(i=0;i<n;i++)
          {
              cin>>a[i];
          }
        findPermutations(a, n); 
      
  }
    
    return 0; 
} 
