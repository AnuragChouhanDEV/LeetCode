// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    bool is_palindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int count = s.size();
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i+1; j < s.size(); ++j) {
                if (is_palindrome(s,i,j)) {
                    count++;
                }
            }
        }
        return count;
    }
};