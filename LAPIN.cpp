#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--) {
	    string s;
	    cin>>s;
	    int arr1[26]={0}, arr2[26]={0};
	    string half, otherHalf;
	    if(s.length()%2==0) {
	        half = s.substr(0, s.length()/2);
	        otherHalf = s.substr(s.length()/2);
	    } else {
	        half = s.substr(0, s.length()/2);
	        otherHalf = s.substr((s.length()/2)+1);
	    } 
	    sort(half.begin(), half.end());
        sort(otherHalf.begin(), otherHalf.end());
        if (half.compare(otherHalf) == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
