// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> ma;
        unordered_map<int,int> ma1;
        for (auto a:arr) ma[a]++;
        for (auto it:ma) {
            if (ma1.find(it.second) != ma1.end())
                return false;
            ma1[it.second]++;
        }
        return true;
    }
};