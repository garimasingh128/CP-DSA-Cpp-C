ALGORITHM


Step 1: Set MIN location 0
Step 2: Search the minimum element in the list
Step 3: Swap with value at location MIN
Step 4: Increment MIN to point to next element
Step 5: Repeat until the list is sorted
	

PSEUDOCODE

procedure selection sort
	list: array f items
	n: size of array
	
	for i = 1 to n
		min = i
		
		for j= i+1 to n
			if list[j] < list[min] then
			min=j
			end if
		end for
		
		swap list[min] and list[i]
	end for
	
end procedure	
