// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int count = 0;
        int idx = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] == 0)
                count++;
            else
                nums[idx++] = nums[i];
        }
        for (int i = idx; i < len; ++i) {
            nums[i] = 0;
        }
    }
};