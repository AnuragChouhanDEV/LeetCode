// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        while (right < k) {
            sum += nums[right];
            ++right;
        }
        while (right < n) {
            sum = max(sum, sum-nums[left]+nums[right]);
            left++;right++;
        }
        return (double)sum/(double)k;
    }
};