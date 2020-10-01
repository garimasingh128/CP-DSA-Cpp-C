ALGORITHM


Step 1: If it is the only element in the list it is already sorted, return.
Step 2: Divide the list recusively into two halves until it can no more be divided.
Step 3: Merge the smaller lists into a new one in a sorted order.

PSEUDOCODE

	procedure mergeSort(var a as array, var l as lower limit, var r as upperlimit)
		if (l<r) 
			var m = l + (r-1)/2
            
            mergeSort(a, l, m)
            mergeSort(a, m+1, r)
            
            merge(a, l, m, r)
            
    end procedure
    
    procedure merge(var a as array, var l as lower limit, var m as middle index, var r as upperlimit)
    	var n1 = m-l+1
    	var n2 = r-m
    	
    	var L as array of size n1
    	var R as array of size n2
    	
    	for i 0 to n1
    		L[i] = a[l+i]
    		
    	for j 0 to n2
    		R[j] = a[m+1+j]
    		
    	i=0
    	j=0
    	k=l
    	while i<n1 and j<n2 
    		if L[i] <= R[j]
    			a[k] = L[i]
    			i++
    		else
    			a[k] = R[j]
    			j++
    		k++
    	end while
    	
    	while i<n1
    		a[k] = L[i]
    		i++
    		k++
    	end while
    	
    	while
    		a[k] = R[j]
    		j++
    		k++
    	end while
    	
    end procedure
    		
    		
    		
    		
    		
    		
