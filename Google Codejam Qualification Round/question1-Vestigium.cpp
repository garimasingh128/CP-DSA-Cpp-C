T = int(input())

def diagonalSum(arr, n):
    sum = 0
    for i in range(n):
        sum += arr[i][i]
        
    return sum


def repeated(arr, n):
    
    repeatr = {}
    repeatc = {}
    countr = 0
    countc = 0
    
    for i in range(n):
        repeatr = dict()
        repeatc = dict()
        
        for j in range(n):
            if arr[j][i] in repeatc:
                repeatc[arr[j][i]] += 1
            else:
                repeatc[arr[j][i]] = 1
            
            if arr[i][j] in repeatr:
                repeatr[arr[i][j]] += 1
            else:
                repeatr[arr[i][j]] = 1
            
        for j in repeatr:
            if repeatr[j] > 1:
                countr+=1
                break
        
        for j in repeatc:
            if repeatc[j]>1:
                countc +=1
                break
                
    return countr,countc
        
    

for x in range(T):
    
    size = int(input())
    matrix = []
    for _ in range(size):
        temp =  list(map(int,input().split()))
        matrix.append(temp)
    
    r,c = repeated(matrix, size)
    print("Case #{}: {} {} {}".format(x+1, diagonalSum(matrix,size), r, c))
