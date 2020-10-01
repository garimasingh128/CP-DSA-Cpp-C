ALGORITHM

Step 1: If it is the first element in the list it is already sorted, return 1.
Step 2: Pick the next element in the list.
Step 3: Compare with all the elements in the sorted sub list.
Step 4: Shift all the elements in the sorted sub-list that are greater than the elemnet to be sorted.
Step 5: Insert the value.
Step 6: Repeat until the list is sorted.
		


PSEUDOCODE

procedure insertonSort(A: array of items) 
	int j
	int key
	
	for i = 1 to length(A) 
		key = A[i]    // Selects the first unsorted element
		j = i-1
		
		while j >= 0 and a[j] > key   //Shifting all the bigger ones
			a[j+1] = a[j]
			j = j-1
		end while
		
		a[j+1] = key          // Inserting at right position
		
	end for
	
			
		
	
	

