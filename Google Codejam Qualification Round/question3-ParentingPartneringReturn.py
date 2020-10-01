from sys import stdin, stdout  

def In(tasks, y):

    check = False
    for x in tasks:
        if max(x[0],y[0]) < min(y[1],x[1]):
            check = True
            break

    return check

def tree(data, index, C, J, string, size):

    if (index>=size):
        return string
    
    elif (not In(C, data[index]) and not In(J,data[index])):
        c = []
        j = []
        j = J.copy()
        c = C.copy()
        j.append(data[index])
        c.append(data[index])
        string2 = tree(data, index+1, C, j, string+"J",size)
        if (string2 != "IMPOSSIBLE"):
            return string2
        else:
            string1 = tree(data, index+1, c, J, string+"C", size)
            return string1

    elif not In(C,data[index]):
        C.append(data[index])
        string += "C"
        string = tree(data, index+1, C, J, string, size)
        return string

    elif not In(J,data[index]):
        J.append(data[index])
        string += "J"
        string = tree(data, index+1, C, J, string, size) 
        return string
        
    else:
        return "IMPOSSIBLE"

def schedule(data,size):
    return tree(data,1, [data[0]], [], "C", size)

T = int(stdin.readline())

for x in range(1, T+1):

    size = int(stdin.readline())
    data = []

    for _ in range(size):
        i, f = map(int,stdin.readline().split())
        data.append((i,f))
    
    print("Case #{}: {}".format(x , schedule(data,size)) )
