// https://leetcode.com/problems/permutations/description/

class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums, vector<int> &v) {
        if (nums.size() == 0) {
            res.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            v.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            helper(nums,v);
            nums.insert(nums.begin()+i, v.back());
            v.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        helper(nums, v);
        return res;
    }
};