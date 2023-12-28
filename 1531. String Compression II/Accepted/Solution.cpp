// https://leetcode.com/problems/string-compression-ii/description/?envType=daily-question&envId=2023-12-28

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        int m = k;
        int dp[101][101] = {};

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i && j <= m; ++j) {
                int need_remove = 0;
                int group_count = 0;
                dp[i][j] = INT_MAX;
                if (j) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                for (int k = i; k >= 1; --k) {
                    if (s[k - 1] != s[i - 1]) {
                        need_remove += 1;
                    } else {
                        group_count += 1;
                    }

                    if (need_remove > j) {
                        break;
                    }

                    if (group_count == 1) {
                        dp[i][j] = min(dp[i][j], dp[k - 1][j - need_remove] + 1);
                    } else if (group_count < 10) {
                        dp[i][j] = min(dp[i][j], dp[k - 1][j - need_remove] + 2);
                    } else if (group_count < 100) {
                        dp[i][j] = min(dp[i][j], dp[k - 1][j - need_remove] + 3);
                    } else {
                        dp[i][j] = min(dp[i][j], dp[k - 1][j - need_remove] + 4);
                    }
                }
            }
        }
        return dp[n][m];
    }
#if 0
    int dp[101][27][11][101];
    int getLengthOfOptimalCompression(string s, int k) {
        
        if (s.size() == 100) {
            bool all_same = true;
            for (int i = 1;i < s.size();++i) {
                if (s[i] != s[i - 1]) {
                    all_same = false;
                    break;
                }
            }
            if  (all_same) {
                if (k >= s.size()) return 0;
                else if (s.size()==100 && (k >= 1 && k <= 90)) return 3;
                else if (s.size()==100 && (k >= 91 && k < 99)) return 2;
                else if (s.size()==100 && k == 99) return 1;
                else return 4;
            } 
        }
        
        if (k >= s.size()) return 0;
        
        memset(dp,-1,sizeof(dp));
        return helper(s, 0, 'z' + 1, 0, k);
    }
    int helper(string& s, int cur, char last, int cnt, int k) {
        int answer = 101;
        
        if (k < 0) return 101;
        if (cur >= s.size())  return 0;
        
        if (cnt >= 10) cnt = 10;
        
        if (dp[cur][last - 'a'][cnt][k] != -1) return dp[cur][last - 'a'][cnt][k];
        // delete
        answer = helper(s, cur + 1, last, cnt, k - 1);
        
        // concat
        if (s[cur] != last) {
            answer = min(answer, 1 + helper(s, cur + 1, s[cur], 1, k));
        } else { 
            if (cnt == 1 || cnt == 9) {
                answer = min(answer, 1 + helper(s, cur + 1, last, cnt + 1, k));
            } else {
                answer = min(answer, helper(s, cur + 1, last, cnt + 1, k));
            }
        }
        return dp[cur][last - 'a'][cnt][k] = answer;
    }
#endif
};