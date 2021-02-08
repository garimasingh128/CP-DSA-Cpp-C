#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result = nums1;
        result.insert(result.end(),nums2.begin(),nums2.end());
        sort(result.begin(),result.end());
        if(result.size()%2!=0) return (double)result[result.size()/2];
        return (double)(result[(result.size()-1)/2]+result[result.size()/2])/2.0;
    }
};