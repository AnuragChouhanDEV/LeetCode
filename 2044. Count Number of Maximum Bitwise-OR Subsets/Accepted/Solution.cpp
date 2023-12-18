// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/

class Solution {
public:
    int res = 0;
    int max_or = 0;
    void helper(vector<int>& nums, int k, int idx) {
        if (nums.size() == idx) {
            if (k == max_or)
                res++;
            return;
        }
        helper(nums, k|nums[idx], idx+1);
        helper(nums, k, idx+1);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for (auto it:nums)
            max_or |= it;
        helper(nums, 0, 0);
        return res;
    }
};
/*
0011
0010
0001
0101

1 + 4 + 4
0111
*/