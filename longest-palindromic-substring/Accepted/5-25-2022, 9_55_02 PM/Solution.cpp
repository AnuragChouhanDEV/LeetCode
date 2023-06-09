// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    bool is_palindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        cout << s << endl;
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
    }
};