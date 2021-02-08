class Solution {
    public int numJewelsInStones(String J, String S) {
           Set<Character> jewels =new HashSet<>();  //set is used so that we dont need to sort the elements as it automatically sorts in nlogn time
        for(char c: J.toCharArray())
            jewels.add(c);
        
        int count =0;
        for(char c :S.toCharArray())
            if(jewels.contains(c)) // i.e we found the jewel thus we increment the count
                count++;
        return count;
        
        
    }
}