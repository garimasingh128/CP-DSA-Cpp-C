//Question Is From Leet Code.
//Question Link:https://leetcode.com/problems/container-with-most-water/

//Language Used:C++
//My Solution:
class Solution {
public:
   int maxArea(vector<int> &height) {
    int ans = 0;
    for (int i = 0, j = height.size() - 1; i < j;) {
    ans = max(ans, (j - i) * min(height[i], height[j]));
        height[i] < height[j] ? i++ : j--;
    }
    return ans;
}

};
