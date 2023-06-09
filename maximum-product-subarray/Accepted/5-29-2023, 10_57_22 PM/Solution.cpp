// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p = 1;
        int s = 1;

        int res = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (p == 0) p = 1;
            if (s == 0) s = 1;
            p = p * nums[i];
            s = s * nums[nums.size()-i-1];
            res = max(res, max(p, s));
        }
        return res;
    }
};