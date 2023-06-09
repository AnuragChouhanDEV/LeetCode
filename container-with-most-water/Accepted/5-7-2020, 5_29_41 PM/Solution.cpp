// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int most_water = 0;
        int l = 0;
        int r = height.size() - 1;
        
        while (l < r) {
            if (height[l] < height[r]) {
                most_water = max(most_water, height[l] * (r-l));
                ++l;
            } else {
                most_water = max(most_water, height[r] * (r-l));
                --r;
            }
        }
        return most_water;
    }
};