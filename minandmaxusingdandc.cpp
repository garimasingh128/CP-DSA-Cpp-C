/* structure is used to return two values from minMax() */
#include<stdio.h> 
struct pair  
{ 
  int min; 
  int max; 
};   
  
struct pair getMinMax(int arr[], int low, int high) 
{ 
  struct pair minmax, mml, mmr;        
  int mid; 
    
  /* If there is only on element */
  if (low == high) 
  { 
     minmax.max = arr[low]; 
     minmax.min = arr[low];      
     return minmax; 
  }     
    
  /* If there are two elements */
  if (high == low + 1) 
  {   
     if (arr[low] > arr[high])   
     { 
        minmax.max = arr[low]; 
        minmax.min = arr[high]; 
     }   
     else
     { 
        minmax.max = arr[high]; 
        minmax.min = arr[low]; 
     }   
     return minmax; 
  } 
    
  mid = (low + high)/2;   
  mml = getMinMax(arr, low, mid); 
  mmr = getMinMax(arr, mid+1, high);   
    
  if (mml.min < mmr.min) 
    minmax.min = mml.min; 
  else
    minmax.min = mmr.min;      
  
  if (mml.max > mmr.max) 
    minmax.max = mml.max; 
  else
    minmax.max = mmr.max;      
   
  return minmax; 
} 
int main() 
{ 
  int arr[] = {10, 4, 6,0,-23,8,9,1,34,66}; 
  int arr_size = 10; 
  struct pair minmax = getMinMax(arr, 0, arr_size-1); 
  printf("Minimum element is %d \n", minmax.min); 
  printf("Maximum element is %d", minmax.max); 
  getchar(); 
} 
