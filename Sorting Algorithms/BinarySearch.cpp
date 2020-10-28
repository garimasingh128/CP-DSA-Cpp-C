PSEUDOCODE

Procedure binary_search 
	A = sorted array
	n = size of array
	x = no to be searched
	
	Set lowerbound = 0
	Set upperbound = n-1
	
	while x not found
		if upperbound < lowerbound
			EXIT: x does not exist
			
		set midPoint = lowerbound + (upperbound - lowerbound) / 2
		
		if A[midPoint] = x
			EXIT: x found at location midPoint
			
		if A[midPoint] < x
			lowerbound = midPoint + 1
			
		if A[midPoint] > x
			upperbound = midPoint - 1
	end while
	
end procedure
	
