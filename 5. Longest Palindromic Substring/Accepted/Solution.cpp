// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:
    string expand_from_center(string s, int i, int j) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;j++;
        }
        return s.substr(i+1, j-i-1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;
        string max_str = s.substr(0,1);
        for (int i = 0; i < n-1; ++i) {
            string odd = expand_from_center(s,i,i);
            string even = expand_from_center(s,i,i+1);
            if (max_str.size() < odd.size())
                max_str = odd;
            if (max_str.size() < even.size())
                max_str = even;
        }
        return max_str;
    }
#if 0
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;
        int len = 1;
        int start_idx = 0;
        int end = 0;
        vector<vector<bool>> dp(n, vector<bool>(n,false));

        for (int i = 0; i < n; ++i) {
            dp[i][i]=true;
            for (int j = 0; j < i; ++j) {
                if (s[i] == s[j] && (i-j <= 2 || dp[j+1][i-1])) {
                    dp[j][i]=true;
                    if (i-j+1 > len) {
                        len = i-j+1;
                        start_idx = j;
                        end = i;
                    }
                }
            }
        }
        return s.substr(start_idx, end-start_idx+1);
    }
#endif
#if 0
    int dp[1001][1001];
    bool helper(string s, int i, int j) {
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) return dp[i][j] = helper(s, i+1, j-1);
        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        int start_idx = 0;
        int len = INT_MIN;
        int n = s.size();
        memset(dp,-1,sizeof(dp));

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (helper(s,i,j)) {
                    if (j-i+1 > len) {
                        len = j-i+1;
                        start_idx = i;
                    }
                }
            }
        }
        return s.substr(start_idx, len);
    }
#endif
};

/*         b  a  b  a  b
        0  1  2  3  4  5
0       0  0  0  0  0  0
1   b   0  1  0  3  0  6
2   a   0     1  0  3  0
3   b   0        1  0  3
4   a   0           1  0
5   b   0              1


*/