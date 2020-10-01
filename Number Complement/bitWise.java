class Solution {
    public int findComplement(int num) {
        if (num==0) // exception for log case as 0 is not used in log
            return 1;
        int num_bit = (int)(Math.log(num)/Math.log(2))+1;
        int mask = (1<<num_bit) - 1;
        return num^mask;
    }
}

//Math.log --have base 10
//so we'll use property log having base a and no. b = log b/log a