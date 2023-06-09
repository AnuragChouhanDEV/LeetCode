// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    bool is_safe(vector<vector<int>>& grid, int x, int y, int size) {
        return (x >= 0 && y >= 0 && x < size && y < size && grid[x][y] == 0);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1 || grid[grid.size()-1][grid.size()-1] == 1) return -1;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) grid[i][j] = 1000000;
            }
        }
        grid[0][0] = 1;
        int dr[8] = {0,1,0,-1,1,-1,-1,1};
        int dc[8] = {1,0,-1,0,1,1,-1,-1};
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        while(!q.empty()) {
            auto it = q.front();
            int dist = it.first;
            int x = it.second.first;
            int y = it.second.second;
            q.pop();
            if (x == grid.size()-1 && y == grid.size()-1) return dist;

            for (int i = 0; i < 8; ++i) {
                int newx = x+dr[i];
                int newy = y+dc[i];
                if (is_safe(grid, newx, newy, grid.size())) {
                    grid[newx][newy] = dist+1;
                    q.push({dist+1, {newx,newy}});
                }
            }
        } 

        return grid[grid.size()-1][grid.size()-1] ? grid[grid.size()-1][grid.size()-1]:-1;
    }
};