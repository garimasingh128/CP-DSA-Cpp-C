class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
         #here we dont need to create hashset, here j itself could be used as hashset
        count=0
        for c in S:
            if c in J:
                count+=1
                
        return count