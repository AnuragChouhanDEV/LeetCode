// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out;
        int product = 1;
        if (nums.size() < 1)
            return out;
        
        for (int i = 0; i < nums.size(); ++i) {
            product *= nums[i];
            out.push_back(product);
        }
        product = 1;
        for (int i = nums.size() -1; i > 0; --i) {
            out[i] = out[i-1] * product;
            product *= nums[i];
            
        }
        out[0] = product;
        return out;
    }
};