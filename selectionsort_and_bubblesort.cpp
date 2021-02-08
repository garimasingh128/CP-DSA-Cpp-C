//Selection Sort and Bubble Sort

#include<bits/stdc++.h>
using namespace std;

#define lli long long int


void selectionSort(int arr[], int size)
{
	int small, temp, k, i=0;
	for(k=0; k < size; k++)
    {
        small = k;
        
        for(i=k; i < size; i++)
        {
            if(arr[small] > arr[i])
                small = i;
        }
        
        temp = arr[k];
        arr[k] = arr[small];
        arr[small] = temp;
    }
}


void bubbleSort(int arr[], int size)
{
	int small, temp, k, i, j;
	for(i=0; i < size; i++)
    {
        for(j=0; j < size-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


void printArray(int arr[], int size) 
{ 
    int i; 
    for(i=0; i < size; i++) 
        cout << arr[i] << " "; 
}


int main() 
{ 

	int ch;
	//int arr[] = {10, 7, 8, 9, 1, 5}; 
	
	//input array size
	int n;
	cout << "Enter array size: ";
	cin >> n;
	
	//input array
	int arr[n];
	cout << "Enter array elements: ";
	
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	
	cout << "Enter Choice -> 1 for Selection Sort and 2 for Bubble Sort: ";
	cin >> ch;
	
	//menu
	switch(ch)
	{
	
		case 1:
		    selectionSort(arr, n); 
		    cout << "Sorted array: "; 
		    printArray(arr, n);
		    break;
		    
		case 2:  
		    bubbleSort(arr, n); 
		    printArray(arr, n); 
		    break;
		    	
		default:
		    break;
	} 
}
