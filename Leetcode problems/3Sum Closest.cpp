#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int sum,mindiff=INT_MAX,ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            for(int j=i+1,k=n-1;j<k;){
                sum=nums[i]+nums[j]+nums[k];
                if(sum==target) return sum;
                if(abs(target-sum) < mindiff){
                    mindiff=abs(target-sum);
                    ans=sum;
                }
                if(sum>target) k--;
                else j++;
            }
        }
        return ans;
    }
};