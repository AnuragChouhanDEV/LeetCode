// https://leetcode.com/problems/combination-sum

class Solution {
public:
    void combination_util(int idx, int target, vector<int> candidates, vector<int> &subset, vector<vector<int>> &result) {
        if (idx == candidates.size()) {
            if (target==0) {
                result.push_back(subset);
            }
            return;
        }
        if (candidates[idx] <= target) {
            subset.push_back(candidates[idx]);
            combination_util(idx, target-candidates[idx], candidates, subset, result);
            subset.pop_back();
        }
        combination_util(idx+1, target, candidates, subset, result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> subset;
        combination_util(0, target, candidates, subset, result);
        return result;
    }
};