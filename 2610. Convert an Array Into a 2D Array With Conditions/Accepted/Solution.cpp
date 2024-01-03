// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/?envType=daily-question&envId=2024-01-02

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> um;
        for (auto &i : nums){
            um[i]++;
        }
        vector<vector<int>> ans;
        while (!um.empty()) {
            vector<int> temp, toErase;
            for (auto &[f, s] : um) {
                temp.emplace_back(f);
                s--;
                if (s == 0)toErase.emplace_back(f);
            }
            ans.emplace_back(temp);
            for (auto &i : toErase){
                um.erase(i);
            }
        }
        return ans;
    }
};