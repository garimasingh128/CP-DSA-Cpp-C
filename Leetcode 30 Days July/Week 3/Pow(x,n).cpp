class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;

        double y = myPow(x,n/2);
        if(n%2==0){

            return y*y;

        }
        else{
            return n < 0 ? 1/x*y*y : x*y*y;
        }
    }
};
