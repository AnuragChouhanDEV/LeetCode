// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        string res = "";
        for (auto it: s)
            count[it]++;
        vector<pair<char,int>> count_vec(count.begin(), count.end());
        sort(count_vec.begin(), count_vec.end(), 
                [](pair<char,int> &p1, pair<char,int> &p2) {
                    return p1.second > p2.second;
                });
        for (auto it:count_vec) {
            for (int i = 0; i < it.second; ++i) {
                res += it.first;
            }
        }
        return res;
    }
};