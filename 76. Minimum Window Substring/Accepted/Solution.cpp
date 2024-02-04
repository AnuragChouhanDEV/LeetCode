// https://leetcode.com/problems/minimum-window-substring/description/?envType=daily-question&envId=2024-02-04

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for (auto it:t)
            map[it]++;
        int total = t.size();
        int start = 0;
        int end = 0;
        int size = INT_MAX;
        int idx = 0;

        while (end < s.size()) {
            if (map[s[end]] > 0)
                total--;
            map[s[end]]--;
            end++;
            while (total == 0) {
                if (end - start <= size) {
                    size = end - start;
                    idx = start;
                }
                if (map[s[start]] == 0)
                    total++;
                map[s[start]]++;
                start++;
            }
        }
        return size == INT_MAX ? "" : s.substr(idx, size);       
    }
};
/*
1 1 1
2 2 2 2 2 0 0 0 0 0 0 0 0 1 2

1 1 1 1 1 0 0 0 0 0 0 0 0 1 1
ADOBEC

1 1 1 2 2 0 0 0 0 0 0 0 0 0 2
BANC
*/