// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    void helper(vector<vector<char>>& grid, int r, int c, int R, int C) {
        if (r >= R || c >= C || r < 0 || c < 0 || grid[r][c] != '1') {
            return;
        }
        grid[r][c] = '2';
        helper(grid, r+1, c, R, C);
        helper(grid, r, c+1, R, C);
        helper(grid, r-1, c, R, C);
        helper(grid, r, c-1, R, C);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int R = grid.size();
        if (R == 0) return 0;
        int C = grid[0].size();

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == '1') {
                    helper(grid, i, j, R, C);
                    ans++;
                }
            }
        }
        return ans;

    }
};