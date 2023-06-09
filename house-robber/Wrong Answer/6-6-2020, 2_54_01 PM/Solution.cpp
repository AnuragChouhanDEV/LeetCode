// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int even = 0;
        int odd = 0;
        for (int i = 0; i < nums.size();++i) {
            if (i & 1) 
                odd += nums[i];
            else
                even += nums[i];
        }
        return odd > even ? odd : even;
        
    }
};