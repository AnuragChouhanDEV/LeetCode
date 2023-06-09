// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int maxl = height[0];
        int maxr = height[height.size()-1];
        int left = 0;
        int res = 0;
        int right = height.size()-1;
        while (left < right) {
            if (height[left] <= height[right]) {
                res += (maxl - height[left]) > 0 ? maxl - height[left] : 0;
                left++;
            }else{
                res += (maxr - height[right]) > 0 ? maxr - height[right] : 0;
                right--;
            }
            maxl = max(maxl, height[left]);
            maxr = max(maxr, height[right]);
        }
        return res;
    }
};