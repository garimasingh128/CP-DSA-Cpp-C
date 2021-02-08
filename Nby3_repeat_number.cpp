
// Find out the number which has occurred more than N/3 times in an array where N is the array size.

int Solution::repeatedNumber(const vector<int> &A) {
    int i = 0;
    int first = INT_MAX, second = INT_MAX;
    int count1 = 0, count2 = 0;
    for(i = 0; i < A.size(); i++)
    {
        if(A[i] == first)
        {
            count1++;
        }
        else if(A[i] == second)
        {
            count2++;
        }
        else if(count1 == 0)
        {
            count1 = 1;
            first = A[i];
        }
        else if(count2 == 0)
        {
            count2 = 1;
            second = A[i];
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;
    for(i = 0; i < A.size(); i++)
    {
        if(A[i] == first)
        {
            count1++;
        }
        if(A[i] == second)
        {
            count2++;
        }
    }
    
    int n = A.size();
    if(count1 > n/3)
    {
        return first;
    }
    else if(count2 > n/3)
        return second;
    return -1;
}
