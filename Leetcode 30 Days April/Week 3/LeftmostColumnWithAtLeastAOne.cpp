/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {

        int mini=-1,i,l,r,mid,c;
        vector<int> v=binaryMatrix.dimensions();
        int n=v[0];
        int m=v[1];
        if(n==0 || m==0)
            return -1;
        r=0;
        c=m-1;
        while(r<n && c>=0)
        {
            if(binaryMatrix.get(r,c)==1)
            {
                mini=c;
                c--;
            }
            else
                r++;
        }
        return mini;
    }
};
