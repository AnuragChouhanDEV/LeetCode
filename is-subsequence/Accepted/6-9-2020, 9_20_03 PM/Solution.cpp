// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len = t.size();
        int idx = 0;
        for (int i = 0; t[i] != '\0'; ++i) {
            //cout << t[i] << " ";
            if (s[idx] == '\0')
                return true;
             //cout << s[idx] << endl;
            if (s[idx] == t[i])
                idx++;
           
        }
        if (s[idx] == '\0')
            return true;
        return false;
    }
};