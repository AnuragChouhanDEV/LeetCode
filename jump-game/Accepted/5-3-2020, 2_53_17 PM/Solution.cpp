// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reuse = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (reuse < i)
                return false;
            reuse = max(reuse,i+nums[i]);
        }
        return true;
    }
};