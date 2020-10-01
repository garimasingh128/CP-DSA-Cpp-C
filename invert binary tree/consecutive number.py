

def giveMeStrings(N, K):
    resultArray = []
    # define what we do when N is 0
    if (N == 0):
        return resultArray
    if (N == 1):
        return [1, 2, 3, 4, 5, 6, 7, 8, 9]
    specialArray = []
    if (K != 0):
        specialArray.extend((K, 0))
    r = 1
    l = r+K
    while(l < 10):
        specialArray.extend((l, r))
        if (K != 0):
            specialArray.extend((r, l))
        r += 1
        l = r+K

    for (l, r) in specialArray:
        s = [l]
        t = 1
        while (t != N):
            t += 1
            if ((s[-1]) == l and K != 0):
                s.append(r)
            else:
                s.extend(l)
        resultArray.append(int(s.join("")))

    return resultArray
