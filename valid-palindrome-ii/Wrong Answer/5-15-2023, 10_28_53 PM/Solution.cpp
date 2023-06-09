// https://leetcode.com/problems/valid-palindrome-ii

class Solution {
public:
    bool validPalindrome(string s) {
        int flag = 1;
        int start = 0;
        int end = s.size()-1;
        while (start < end) {
            if (s[start] != s[end]) {
                if (flag) {
                    if (s[start+1] == s[end]) {
                        start++;
                    } else if (s[start] == s[end-1]) {
                        end--;
                    } else return false;
                    flag = 0;
                    continue;
                }
                return 0;
            }
            start++;
            end--;
        }
        return true;
    }
};