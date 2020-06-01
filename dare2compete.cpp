#include <bits/stdc++.h> 
using namespace std; 
  

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    long int a,b,c;
    cin>>a;
    cout<<a<<endl;
    cin>>b>>c;
    vector<long int>B;
    vector<long int>A;
    for (long int i = 0; i < c; i++) 
	{
		long int input;
		A.push_back(input);
		cin >> input;
	}
    while(b--){
        for(long int i=0;i<c;i++){
            B.push_back(A[i]);
        }
    }
    long int xor_arr = 0; 
  
    // Iterating through every element in 
    // the array 
    for (long int i = 0; i < (c*b); i++) { 
  
        // Find XOR with the result 
        xor_arr = xor_arr ^ B[i]; 
    } 
    cout<<xor_arr;

    return 0;
}
