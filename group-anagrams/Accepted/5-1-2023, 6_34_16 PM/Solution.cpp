// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ma;
        vector<vector<string>> res;
        string tmp;
        for (auto it:strs) {
            tmp = it;
            sort(tmp.begin(),tmp.end());
            ma[tmp].push_back(it);
        }
        for (auto it=ma.begin();it!=ma.end();++it)
            res.push_back(it->second);
        return res;
    }
};