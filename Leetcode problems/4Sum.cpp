#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> resultVec;
        unordered_set<string> setVal;
        int n = nums.size();
        for(int i=0; i < n-3; i++)
        {
            for(int j=i+1; j < n-2; j++)
            {
                int left = j+1;
                int right= n-1;
                while(left<right)
                {
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum > target)
                    {
                        right--;
                    } else if(sum < target)
                    {
                        left++;
                    } else {
                        vector<int> tempVec{nums[i], nums[j], nums[left], nums[right]};
                        string hashVal = to_string(nums[i]) + to_string(nums[j]) + to_string(nums[left]) + to_string(nums[right]);
                        if(setVal.find(hashVal)==setVal.end())
                        {
                            resultVec.push_back(tempVec);
                            setVal.insert(hashVal);    
                        }
                        left++;
                        right--;
                    }
                }
            }
        }
        return resultVec;
    }
};