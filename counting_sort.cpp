// This Algorithm sorts the given sequence of non-negative integers numbers in O(n) time where n is the size of the sequence. The only thing that it demands is the largest integer in the sequence. if the largest number is k then its space complexity is O(k+n)

#include<iostream>
using namespace std;

int main(){
    int k = 0, n;
    // Takes input for the size of the sequence
    cin >> n;
    // Array for storing the sequence
    int a[n];
    
    // Takes input for the array a
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(k < a[i]){
	    k = a[i];
	    }
    }
    
    // Array for storing the frequency of each number in the array a
    int b[k+1];

    // First make each of the elements of b 0 
    for(int i = 0; i <= k; i++){
        b[i] = 0;
    }

    // Count the frequency of each integer and store it in b
    for(int i = 0; i < n; i++){
        b[a[i]]++;
    }

    // Print the numbers according to the frequency
    for(int i = 0; i <= k; i++){
        while(b[i]!=0){
            cout << i << " ";
            b[i]--;
        }
    }
}
