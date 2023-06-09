// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (num.size() == 0)
            return 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res ^= nums[i];
        }
        return res;
    }
};