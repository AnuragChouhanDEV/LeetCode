// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int final_len = 0;
        for (int i = 0; i < len; ++i) {
            int j;
            for (j = 0; j < i;++j) {
                if (s[i] == s[j])
                    break;
            }
            if (i == j)
                final_len++;
        }
        return final_len;
    }
};