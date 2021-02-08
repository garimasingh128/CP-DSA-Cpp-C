class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        for(char c: J)
            jewels.insert(c);
        
        int count =0;
        for(char c :S)
            if(jewels.find(c) != jewels.end()) count++;
        return count;
        
    }
};


// A HashSet holds a set of objects, but in a way that it allows you to easily and quickly determine whether an object is already in the set or not. It does so by internally managing an array and storing the object using an index which is calculated from the hashcode of the object
