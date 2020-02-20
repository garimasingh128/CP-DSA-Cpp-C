// C++ program to check whether two strings are anagrams 
// of each other 
#include <bits/stdc++.h> 

using namespace std; 

int partition (char arr[], int low, int high) 
{ 
    int pivot = (int)arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if ((int)arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            char temp = arr[i];
            arr[i]=arr[j];
            arr[j]= temp;
        } 
    } 
	char temp = arr[i+1];
            arr[i+1]=arr[high];
            arr[high]= temp; 
    return (i + 1); 
} 
  
void quickSort(char arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
/* function to check whether two strings are anagram of 
each other */
bool areAnagram(char str1[], char str2[]) 
{ 
	// Get lengths of both strings 
	int n1 = strlen(str1); 
	int n2 = strlen(str2); 

	// If length of both strings is not same, then they 
	// cannot be anagram 
	if (n1 != n2) 
		return false; 
		
    quickSort(str1, 0, n1-1); 
    
    quickSort(str2, 0, n2-1); 
    
	// Compare sorted strings 
	for (int i = 0; i < n1; i++) 
		if (str1[i] != str2[i]) 
			return false; 

	return true; 
} 

int main() 
{ 
char str1[100], str2[100];
cout<<"enter 1st string";
cin>>str1;
cout<<"enter 2nd string";
cin>>str2;
	if (areAnagram(str1, str2)) 
		cout << "The two strings are anagram of each other"; 
	else
		cout << "The two strings are not anagram of each other"; 
	return 0; 
} 
