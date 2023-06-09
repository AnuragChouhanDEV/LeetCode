// https://leetcode.com/problems/ones-and-zeroes

class Solution {
public:
    void count_0_and_1(int *count, string s) {
        for (char c:s) {
            count[c-'0']++;
            //cout << c-'0' << endl;
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1];
        for (int i = m; i >= 0; --i) {
            for (int j = n; j >= 0; --j) {
                dp[i][j] = 0;
            }
        }
        for (auto s:strs) {
            int count[2] = {0};
            count_0_and_1(count, s);
            for (int i = m; i >= count[0]; --i) {
                for (int j = n; j >= count[1]; --j) {
                    dp[i][j] = max(dp[i][j], 1+dp[i-count[0]][j-count[1]]);
                }
            }
        }
        return dp[m][n];
    }
};