def balance(arr, size):
    stack = []
    stacklength = len(stack)
    
    String = "" 
    String += (arr[0]*'(') + str(arr[0])
    stacklength += arr[0]
    index = 0
    
    while index<size-1:
        
        if arr[index+1] == 0:
            String += ')'*stacklength + str(0)
            index += 1
            stacklength = 0
        
        elif arr[index+1] > arr[index]:
            diff = arr[index+1]-arr[index]
            String += '('*diff + str(arr[index+1])
            stacklength = arr[index+1]
            index += 1
        
        elif arr[index+1] < arr[index]:
            diff = stacklength-arr[index+1]
            String += ')'*diff + str(arr[index+1])
            stacklength = arr[index+1]
            index+=1
        
        elif arr[index+1] == arr[index]:
            String += str(arr[index+1])
            index+=1
    
    String += ')'*stacklength
    return String
    
    
    
T = int(input())

for x in range(T):
    size = 0
    arr = []
    for i in input():
        arr.append(int(i))
        size+=1
    
    print("Case #{}: {}".format(x+1,balance(arr, size)))
    
    
