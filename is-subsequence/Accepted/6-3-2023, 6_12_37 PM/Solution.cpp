// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l1 = 0;int l2 = 0;
        int r1 = s.size();
        int r2 = t.size();
        while (l1 < r1 && l2 < r2) {
            if (s[l1] == t[l2]) {
                l1++;l2++;
                continue;
            }
            l2++;
        }
        return l1 == r1;
    }
};