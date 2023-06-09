// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> ma;
        unordered_set<int> ma1;
        for (auto a:arr) ma[a]++;
        for (auto it:ma) {
            if (ma1.count(it.second))
                return false;
            ma1.insert(it.second);
        }
        return true;
    }
};