// https://leetcode.com/problems/buddy-strings

class Solution {
public:
    bool isPalindrome(string S)
    {
        string P = S;
        reverse(P.begin(), P.end());
        if (S == P) {
            return true;
        } else {
            return false;
        }
    }
    bool buddyStrings(string s, string goal) {
        int idx1 = -1;
        int idx2 = 0;
        int i;
        if(isPalindrome(goal))
            return true;
        for (i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i]) {
                if (idx1 == -1) {
                    idx1 = i;
                } else {
                    idx2 = i;
                    break;
                }
            }
        }
        if (i == s.size() && idx1 == -1)
            return false;
        swap(s[idx1], s[idx2]);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i])
                return false;
        }
        return true;
    }
};