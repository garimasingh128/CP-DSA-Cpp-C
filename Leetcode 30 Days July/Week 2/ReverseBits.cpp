class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        int i;
        uint32_t f=0;
        for(i=0;i<32;i++)
        {
            if( n & 1<<i)
            {
                f|= (1<<(31-i));

            }
        }
        return f;
    }
};
