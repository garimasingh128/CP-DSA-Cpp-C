class Solution {
public:
    int findComplement(int num) {
        if (num==0) // exception for log case as 0 is not used in log
            return 1;
        int num_bit = log2(num)+1;
        int mask = (unsigned)(1<<num_bit) - 1;
        return num^mask;
        
    }
};