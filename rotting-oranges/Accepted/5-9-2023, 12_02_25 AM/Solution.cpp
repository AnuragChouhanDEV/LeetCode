// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int time = 0;
        int fresh = 0;
        queue<pair<int,int>> coo;

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C;++j) {
                if (grid[i][j] == 2) 
                    coo.push({i,j});
                if (grid[i][j] == 1)
                    fresh++;
            }
        }
        while(!coo.empty()) {
            int rot = coo.size();
            for (int i =0; i < rot; ++i) {
                int x = coo.front().first;
                int y = coo.front().second;
                coo.pop();
                if (x > 0 && grid[x-1][y] == 1) {
                    grid[x-1][y] = 2;
                    fresh--;
                    coo.push({x-1,y});
                }
                if (y > 0 && grid[x][y-1] == 1) {
                    grid[x][y-1] = 2;
                    fresh--;
                    coo.push({x,y-1});
                }
                if (x < R-1 && grid[x+1][y] == 1) {
                    grid[x+1][y] = 2;
                    fresh--;
                    coo.push({x+1,y});
                }
                if (y < C-1 && grid[x][y+1] == 1) {
                    grid[x][y+1] = 2;
                    fresh--;
                    coo.push({x,y+1});
                }
            }
            if (!coo.empty())
                time++;
        }
        return fresh == 0 ? time:-1;
    }
};