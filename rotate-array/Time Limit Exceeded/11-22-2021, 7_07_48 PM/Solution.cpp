// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size() - 1;
        while(k--) {
            for (int i = size; i > 0; --i) {
                swap(nums[i],nums[i-1]);
            }
        }
        return;
    }
};