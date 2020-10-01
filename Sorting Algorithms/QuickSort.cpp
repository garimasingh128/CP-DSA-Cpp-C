ALGORITHM

Step 1: Choose the highest index as pivot.
Step 2: Take two variables to point to left and right of the list excluding pivot. 
Step 3: Left to lower index and right to higher.
Step 4: While value at left is less than pivot move right.
Step 5: While value at right is more than pivot move left.
Step 6: If step 4 and 5 doesn't match then swap them.
Step 7: If left>=right, the point where they meet is the correct position of the pivot.

PSUEDOCODE

procedure quickSort()
	var arr as array
	var low as lower index
	var high as higher index
	
	if low < high then
		var p = partition(arr, low, high)
		quickSort(arr,low,pi-1)
		quickSort(arr,pi+1,high)
	end if
end procedure

procedure partition(arr, low, high) 
	var pivot = arr[high] 
	var i = low-1
	var j = 0
	
	for j = 0 to high-1
		if arr[j] < pivot then
			i++
			swap(arr[i], arr[j])
		end if
	end for
	
	swap(arr[i+1], arr[high])
	return i+1
end procedure
	
		
	
	
	
	
	
	
	
