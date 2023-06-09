// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1 || grid[grid.size()-1][grid.size()-1] == 1) return -1;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) grid[i][j] = 1000000;
            }
        }
        grid[0][0] = 1;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i==0 && j == 0) {;continue;}
                else if (i==0) { 
                    if (grid[i][j] == 0) grid[i][j] = 1+grid[i][j-1];}
                else if (j==0) { 
                    if (grid[i][j] == 0) grid[i][j] = 1+grid[i-1][j];}
                else {
                    if (grid[i][j] == 0)
                        grid[i][j] = 1+min(grid[i-1][j], min(grid[i][j-1], grid[i-1][j-1]));
                }
            }
        }

        return grid[grid.size()-1][grid.size()-1] ? grid[grid.size()-1][grid.size()-1]:-1;
    }
};