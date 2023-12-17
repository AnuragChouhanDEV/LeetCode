// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

class Solution {
public:
    vector<int> sset;
    int res = 0;
    void generate_subsets(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            int xorres = 0;
            for (auto it:sset)
                xorres ^= it;
            res += xorres;
            return;
        }
        sset.push_back(nums[idx]);
        generate_subsets(nums, idx+1);
        sset.pop_back();
        generate_subsets(nums, idx+1);
    }
    int subsetXORSum(vector<int>& nums) {
        generate_subsets(nums, 0);
        return res;
    }
};