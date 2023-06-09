// https://leetcode.com/problems/rotate-array

class Solution {
    void reverse(vector<int>& nums, int start, int end) {
        int temp = nums[start];
        while (start < end) {
            temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        cout << nums.size() << endl;
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};