// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hay = haystack.length();
        int n = needle.length();
        if (n == 0)
            return 0;
        if (hay < n)
            return -1;
        for (int i = 0; i <= hay - n; ++i) {
            int j = 0;
            for (j = 0; j < n; ++j) {
                if (haystack[i+j] != needle[j])
                    break;
            }
            if (j == n)
                return i;
        }
        return -1;
    }
};