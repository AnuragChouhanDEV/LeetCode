// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    bool is_palindrome(string s) {
        int i = 0;
        int j = s.size();
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int size = s.length();
        int start = 0;
        int end = 1;
        int max_length = 1;
        for (int i = 0; i < size; ++i) {
            for (int j = i+1; j < size; ++j) {
                int flag = 1;
                flag = is_palindrome(s);
                if (flag && j - i +1 > max_length) {
                    max_length = j - i +1;
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr(start, end);
    }
};