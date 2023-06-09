// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last_val = nums.size()-1;
        for (int i = nums.size()-1; i >= 0; --i) {
            if (i + nums[i] >= last_val)
                last_val = i;
        }
        return last_val == 0;
    }
};