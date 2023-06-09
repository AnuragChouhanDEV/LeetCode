// https://leetcode.com/problems/permutations

class Solution {
public:
    void permute_util(vector<int>& nums, int idx, vector<vector<int>> &result) {
        if (idx == nums.size()-1) {
            result.push_back(nums);
            return;
        }
        for (int i = idx; i <= nums.size()-1; ++i) {
            swap(nums[i], nums[idx]);
            permute_util(nums, idx+1, result);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permute_util(nums, 0, result);
        return result;
    }
};