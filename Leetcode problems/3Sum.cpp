#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;
        sort( nums.begin(), nums.end() );
        for( int i=0; i<nums.size(); ){
            if(nums[i] > 0) break;
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int s = nums[i] + nums[left] + nums[right];
                if(s<0) left++;
                else if(s>0) right--;
                else{
                    res.push_back(vector<int>({nums[i],nums[left],nums[right]}));
                    left++; right--;
                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }
            }
            i++;
            while(i>0 && i<nums.size() && nums[i]==nums[i-1]) i++;
        }
        return res;
    }
};