// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
            maxi = max(sum, maxi);
            sum = sum < 0 ? 0 : sum;
        }
        return maxi;
    }
};