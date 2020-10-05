
#include <bits/stdc++.h> 
using namespace std; 

// Returns true if num is triangular 
bool isTriangular(int num) 
{ 
	if (num < 0) 
		return false; 

	// Considering the equation n*(n+1)/2 = num 
	// The equation is : a(n^2) + bn + c = 0"; 
	int c = (-2 * num); 
	int b = 1, a = 1; 
	int d = (b * b) - (4 * a * c); 

	if (d < 0) 
		return false; 

	// Find roots of equation 
	float root1 = ( -b + sqrt(d)) / (2 * a); 
	float root2 = ( -b - sqrt(d)) / (2 * a); 

	// checking if root1 is natural 
	if (root1 > 0 && floor(root1) == root1) 
		return true; 

	// checking if root2 is natural 
	if (root2 > 0 && floor(root2) == root2) 
		return true; 

	return false; 
} 

// Driver code 
int main() 
{ 
	int num;
	cin>>num; 
	if (isTriangular(num)) 
		cout << "YES"; 
	else
		cout << "NO"; 

	return 0; 
} 

