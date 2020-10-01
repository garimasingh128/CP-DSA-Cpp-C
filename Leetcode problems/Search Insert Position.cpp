#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) return i;
            else if(nums[i]!=target){
                if(target<nums[i]) return i;
            }
        }
        return i;
    }
};