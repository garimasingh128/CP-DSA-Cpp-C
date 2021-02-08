// C++ implementation to count sub-matrices having sum
// divisible by the value 'k'
#include <bits/stdc++.h>
using namespace std;

#define SIZE 10

// function to count all sub-arrays divisible by k
int subCount(int arr[], int n, int k)
{
	// create auxiliary hash array to count frequency
	// of remainders
	int mod[k];
	memset(mod, 0, sizeof(mod));

	// Traverse original array and compute cumulative
	// sum take remainder of this current cumulative
	// sum and increase count by 1 for this remainder
	// in mod[] array
	int cumSum = 0;
	for (int i = 0; i < n; i++) {
		cumSum += arr[i];

		// as the sum can be negative, taking modulo
		// twice
		mod[((cumSum % k) + k) % k]++;
	}

	int result = 0; // Initialize result

	// Traverse mod[]
	for (int i = 0; i < k; i++)

		// If there are more than one prefix sub arrays
		// with a particular mod value.
		if (mod[i] > 1)
			result += (mod[i] * (mod[i] - 1)) / 2;

	// add the sub arrays starting from the arr[i]
	// which are divisible by k itself
	result += mod[0];

	return result;
}

// function to count all sub-matrices having sum
// divisible by the value 'k'
int countSubmatrix(int mat[SIZE][SIZE], int n, int k)
{
	// Variable to store the final output
	int tot_count = 0;

	int left, right, i;
	int temp[n];

	// Set the left column
	for (left = 0; left < n; left++) {

		// Initialize all elements of temp as 0
		memset(temp, 0, sizeof(temp));

		// Set the right column for the left column
		// set by outer loop
		for (right = left; right < n; right++) {

			// Calculate sum between current left
			// and right for every row 'i'
			for (i = 0; i < n; ++i)
				temp[i] += mat[i][right];

			// Count number of sub arrays in temp[]
			// having sum divisible by 'k' and then
			// add it to 'tot_count'
			tot_count += subCount(temp, n, k);
		}
	}

	// required count of sub-matrices having sum
	// divisible by 'k'
	return tot_count;
}

// Driver program to test above
int main()
{
	int mat[][SIZE] = { { 5, -1, 6 },
						{ -2, 3, 8 },
						{ 7, 4, -9 } };
	int n = 3, k = 4;
	cout << "Count = "
		<< countSubmatrix(mat, n, k);
	return 0;
}
