// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int start_idx = 0;
        int end_idx = 0;
        vector<vector<int>> dp(len,vector<int>(len));
        for (int i = 0; i < len;++i) {
            for (int j = i; j < len;++j) {
                if (i == j) {
                    dp[i][j] = 1;
                } else {
                    if (j == i+1 && j < len) {
                        if (s[i] == s[j]) {
                            dp[i][j] = 1;
                            start_idx = i;
                            end_idx = j; 
                        }
                        else
                            dp[i][j] = 0;
                    }
                }
               // cout << dp[i][j] << " ";
            }
           // cout << endl;
        }
        cout << endl;
        for (int i = 0; i < len;++i) {
            for (int j = i; j < len;++j) {
                if (i+1 < j) {
                    if (j > 1 && j < len && (s[i] == s[j]) && dp[i+1][j-1] == 1) {
                        dp[i][j] = 1;
                        start_idx = i;
                        end_idx = j;        
                    } else {
                        //cout << i << " " << j << endl; 
                        dp[i][j] = 0;
                    }
                }
            //    cout << dp[i][j] << " ";
            }
          //  cout << endl;
        }
        //cout << start_idx << " " << end_idx << endl;
        return s.substr(start_idx, end_idx - start_idx + 1);
    }
};