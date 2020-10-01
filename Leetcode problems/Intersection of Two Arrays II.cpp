#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> hash;
        for(auto itr:nums1) hash[itr]++;
        for(auto itr2:nums2){
            if(hash[itr2]>0){
                ans.push_back(itr2);
                hash[itr2]--;
            }
        }
        return ans;
    }
};