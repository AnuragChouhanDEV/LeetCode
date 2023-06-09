// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int R = mat.size();
        int C = mat[0].size();
        vector<vector<bool>> vis(R, vector<bool>(C, false));
        vector<vector<int>> res(R, vector<int>(C, 0));
        queue<pair<pair<int,int>, int>> q;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (mat[i][j] == 0) {
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }
        int dr[] = {0,1,-1,0};
        int dc[] = {1,0,0,-1};
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            res[row][col] = steps;

            for (int i = 0; i < 4; ++i) {
                int r = row+dr[i];
                int c = col+dc[i];
                if (r >= 0 && c >= 0 && r < R && c < C && !vis[r][c]) {
                    vis[r][c] = true;
                    q.push({{r,c},steps+1});
                }
            }
        }
        return res;
    }
};