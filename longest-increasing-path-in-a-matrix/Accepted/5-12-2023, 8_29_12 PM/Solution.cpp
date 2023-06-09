// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:
    int helper(vector<vector<int>>& grid, int r, int c, int R, int C, vector<vector<int>> &visited) {
        if (r >= R || c >= C || r < 0 || c < 0) {
            return 0;
        }
        if (visited[r][c] != 0)
            return visited[r][c];
        int curr_max = 1;
        if (r+1 < R && grid[r+1][c] > grid[r][c])
            curr_max = max(curr_max, 1+helper(grid, r+1, c, R, C, visited));
        if (c+1 < C && grid[r][c+1] > grid[r][c])
            curr_max = max(curr_max, 1+helper(grid, r, c+1, R, C, visited));
        if (r-1 >= 0 && grid[r-1][c] > grid[r][c])
            curr_max = max(curr_max, 1+helper(grid, r-1, c, R, C, visited));
        if (c-1 >= 0 && grid[r][c-1] > grid[r][c])
            curr_max = max(curr_max, 1+helper(grid, r, c-1, R, C, visited));

         visited[r][c] = curr_max;
         return curr_max;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        int count = 0;
        vector<vector<int>> visited(R, vector<int>(C,0));

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                count = max(count, helper(matrix, i, j, R, C, visited));
            }
        }
        return count;
    }
};