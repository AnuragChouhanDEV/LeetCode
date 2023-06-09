// https://leetcode.com/problems/flood-fill

class Solution {
public:
    void helper(vector<vector<int>>& grid, int r, int c, int R, int C, int color, int new_color) {

        if (r >= R || c >= C || r < 0 || c < 0 || grid[r][c] != color || grid[r][c] == new_color) {
            return;
        }
        grid[r][c] = new_color;

        helper(grid, r+1, c, R, C, color, new_color);
        helper(grid, r, c+1, R, C, color, new_color);
        helper(grid, r-1, c, R, C, color, new_color);
        helper(grid, r, c-1, R, C, color, new_color);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int R = image.size();
        int C = image[0].size();
        helper(image, sr, sc, R, C, image[sr][sc],color);
        return image;
    }
};