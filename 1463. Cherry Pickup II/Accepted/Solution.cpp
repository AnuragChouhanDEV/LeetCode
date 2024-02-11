// https://leetcode.com/problems/cherry-pickup-ii/description/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<vector<int>>> dp(R + 1, vector<vector<int>>(C + 1, vector<int>(C + 1, -1)));
        dp[0][0][C-1] = grid[0][0] + grid[0][C-1]; // sum elements from row 0

        int res = 0;
        for (int row = 1; row < R; ++row) { // traverse all row
            for(int aj = 0; aj < C; ++aj) { // bot a traversal
            for(int bj = aj+1; bj < C; ++bj) { // bot b traversal
            for(int a = aj-1; a <= aj+1; ++a) { // bot a {-1,0,1}
                for(int b = bj-1; b <= bj+1; ++b) { // bot b {-1,0,1}
                    if(a >= 0 && a < C && b >= 0 && b < C) {
                        int prev_el = dp[row-1][a][b];
                        if (prev_el == -1) continue;
                        dp[row][aj][bj] = max(dp[row][aj][bj], prev_el + grid[row][aj] + (aj != bj ? grid[row][bj] : 0));
                    }
                }
            }
            res = max(res, dp[row][aj][bj]);
            }
            }
        }

        return res;
}

#if 0
    int dfs(int row, int aj, int bj, int R, int C, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        if (row < 0 || row >= R || aj < 0 || aj >= C || bj < 0|| bj >= C) return 0;
        if (dp[row][aj][bj] != -1) return dp[row][aj][bj];
        int sum = grid[row][aj] + grid[row][bj];
        int maxi = 0;
        for (int a = aj-1; a <= aj+1; ++a) {
            for (int b = bj-1; b <= bj+1; ++b) {
                if (a < b)
                    maxi = max(maxi, dfs(row+1, a, b, R, C, grid, dp));
            }
        }
        sum += maxi;
        return dp[row][aj][bj] = sum;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<vector<int>>> dp(R+1,vector<vector<int>>(C+1, vector<int>(C+1, -1)));
        int res = 0;
        for (int i = 1; i < R; ++i) {
            res = dfs(0, 0, C-1, R, C, grid, dp);
        }
        return res;
    }
#endif
};
/*

*/