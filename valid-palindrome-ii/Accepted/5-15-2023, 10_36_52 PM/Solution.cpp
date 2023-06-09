// https://leetcode.com/problems/valid-palindrome-ii

class Solution {
public:
    bool validPalindrome(string s) {
        int flag = 1;
        int count1 = 0;
        int count2 = 0;
        int start = 0;
        int end = s.size()-1;
        while (start < end) {
            if (s[start] != s[end]) {
                count1++;start++;
            } else {
                start++;end--;
            }
        }
        start = 0;end = s.size()-1;
        while (start < end) {
            if (s[start] != s[end]) {
                count2++;end--;
            } else {
                start++;end--;
            }
        }
        if (count1 == 1 || count2 == 1) return true;
        if (count1 == 0 && count2 == 0) return true;
        return false;
    }
};