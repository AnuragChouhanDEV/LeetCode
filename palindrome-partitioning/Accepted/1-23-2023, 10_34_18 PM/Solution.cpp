// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    bool is_palindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void recur(string s, vector<string> &temp, int idx, vector<vector<string>> &ans) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < s.size(); ++i) {
            if (is_palindrome(s, idx, i)) {
                temp.push_back(s.substr(idx, i-idx+1));
                recur(s, temp, i+1, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        recur(s, temp, 0, ans);
        return ans;
    }
};