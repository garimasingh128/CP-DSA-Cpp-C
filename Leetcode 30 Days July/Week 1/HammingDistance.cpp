class Solution {
public:
    int hammingDistance(int x, int y) {

        int r=x^y,c=0;

        while(r)
        {
            r=r&(r-1);
            c++;
        }
        return c;

    }
};
