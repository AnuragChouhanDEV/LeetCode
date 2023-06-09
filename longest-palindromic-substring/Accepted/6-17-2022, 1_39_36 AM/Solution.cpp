// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    int is_palindrome(string s, int l, int r) {
        int left = l;
        int right = r;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;right++;
        }
        return right - left -1;
    }
    string longestPalindrome(string s) {
#if 0
        if (s.size() < 1)
            return "";
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); ++i) {
            int len1 = is_palindrome(s,i,i);
            int len2 = is_palindrome(s,i,i+1);
            int len = max(len1, len2);
            if (len > (end - start)) {
                start = i - ((len-1)/2);
                end = i + (len/2);
                //cout << "   " << start << " " << end << endl;
            }
        }
        return s.substr(start, end+1);
#else
        int size = s.length();
        int start = 0;
        int end = 1;
        int max_length = 1;
        bool table[size][size];
        memset(table, 0, sizeof(table));
        for (int i = 0; i < size;++i)
            table[i][i] = true;
        
        for (int i = 0; i < size-1;++i) {
            if (s[i] == s[i+1]) {
                table[i][i+1] = true;
                start = i;
                max_length = 2;
            }
        }
        for (int k = 3; k <= size;++k) {
            for (int i =0; i < size-k+1;++i) {
                int j = i+k-1;
                if (table[i+1][j-1] && s[i] == s[j]) {
                    table[i][j] = true;
                    if (k > max_length) {
                        start = i;
                        max_length = k;
                    }
                }
            }
        }
        
        return s.substr(start, max_length);
#endif
    }
};