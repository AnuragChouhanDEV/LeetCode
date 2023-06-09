// https://leetcode.com/problems/buddy-strings

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int idx1 = -1;
        int idx2;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i]) {
                if (idx1 == -1) {
                    idx1 = i;
                } else {
                    idx2 = i;
                }
            }
        }
        swap(s[idx1], s[idx2]);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i])
                return false;
        }
        return true;
    }
};