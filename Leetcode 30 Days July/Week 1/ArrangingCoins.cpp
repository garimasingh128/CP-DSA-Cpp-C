class Solution {
public:
    int arrangeCoins(int n) {
        int count = 0;
        int i = 1;
        while(n) {
            n = n - i;
            if(n < 0) {
                break;
            }
            count++;
            i = i + 1;
        }
        return count;
    }
};
