int Solution::solve(vector<int> &A) {
    int start = 0, end = A.size() - 1;
    int mid, n = A.size();
    //cout<<A[0]<<" "<<A[n-1]<<endl;
    while(start <= end)
    {
        mid = start + (end - start) / 2;
        if(mid > 0 && mid < n-1)
        {
            if((A[mid] >= A[mid-1]) && (A[mid] >= A[mid+1]))
                return A[mid];
            else if(A[mid-1] > A[mid])
                end = mid - 1;
            else if(A[mid] < A[mid+1])
                start = mid + 1;
        }
        else
        {
            break;
        }
    }
    if(A[0] > A[n-1])
    {
        return A[0];
    }
    return A[n-1];
}
