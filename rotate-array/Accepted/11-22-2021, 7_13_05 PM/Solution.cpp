// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void reverse(vector<int>& nums, int i, int j) {
        while(i < j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            ++i;
            --j;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int size = nums.size() - 1;
        k = k % nums.size();
        reverse(nums, 0, size);
        reverse(nums, 0, k-1);
        reverse(nums, k, size);
    }
};