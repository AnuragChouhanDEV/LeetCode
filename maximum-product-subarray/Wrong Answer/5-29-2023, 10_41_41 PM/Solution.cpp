// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int res = INT_MIN;
        int prod = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            prod *= nums[i];
            res = max(res, prod);
        }
        prod = nums[nums.size()-1];
        for (int i = nums.size()-2; i >= 0; --i) {
            prod *= nums[i];
            res = max(res, prod);
        }
        return res;
    }
};