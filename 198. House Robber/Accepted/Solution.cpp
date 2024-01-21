// https://leetcode.com/problems/house-robber/description/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        for (int i = 2; i < n; ++i) {
            if (i == 2) {
                nums[i] += nums[i-2];
            } else {
                nums[i] += max(nums[i-2], nums[i-3]);
            }
        }
        return max(nums[n-1], nums[n-2]);
    }
};
/*
2 7 11 10 12
1 2 3 1 3 5 7 9
1 2 4 3 7 9 14 18
*/
