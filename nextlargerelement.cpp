#include <bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement( vector<int>& arr, int n) {
   // int n=arr.size();
     stack < int > s; 
  
  /* push the first element to stack */
  s.push(arr[0]); 
  
  // iterate for rest of the elements 
  for (int i = 1; i < n; i++) { 
  
    if (s.empty()) { 
      s.push(arr[i]); 
      continue; 
    } 
  
    /* if stack is not empty, then 
       pop an element from stack. 
       If the popped element is smaller 
       than next, then 
    a) print the pair 
    b) keep popping while elements are 
    smaller and stack is not empty */
    while (s.empty() == false && s.top() < arr[i]) 
    {          
        cout<< arr[i] <<" "; 
        s.pop(); 
    } 
  
    /* push next to stack so that we can find 
    next greater for it */
    s.push(arr[i]); 
  } 
  
  /* After iterating over the loop, the remaining 
  elements in stack do not have the next greater 
  element, so print -1 for them */
  while (s.empty() == false) { 
    cout << "-1"<<" "; 
    s.pop(); 
  } 
} 
    //A[n-1]=-1;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=i+1;j<n;j++)
    //     {
    //         if(A[i]<A[j])
    //         {
    //         A[i]=A[j];
    //         break;
    //         }
    //     }
    // }

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for ( int i = 0; i < n; i++) cin >> A[i];

    nextLargerElement(A,n);
 
}







