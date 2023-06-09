// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<int>> dp(R, vector<int> (C, 0));
        dp[0][0] = grid[0][0];
        for (int j = 1; j < C; ++j) {
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }
        for (int i = 1; i < R; ++i) {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for (int i = 1; i < R; ++i) {
            for (int j = 1; j < C; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[R-1][C-1];
    }
};