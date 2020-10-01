#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, i = 0, j = height.size() -1;
        while (i < height.size() && j >= 0) {
            maxArea = max (maxArea, min (height[i], height[j]) * (j - i));
            if (height[i] < height[j]) i++; else j--;
        }
        return maxArea;
    }
};