// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves

class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() <= 4) return 0;
        return nums[nums.size()-4]-nums[0];
    }
};