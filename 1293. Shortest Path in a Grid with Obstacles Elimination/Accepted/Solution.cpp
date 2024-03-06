// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/

class Solution {
public:
    struct obstacles {
        int x;
        int y;
        int rem_k;
        int moves;
    };
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<struct obstacles> q;
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m][k+1];
        memset(dp, 0, sizeof dp);
        dp[0][0][k] = 1;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        q.push({0, 0, k, 0});
        while(!q.empty()){
            struct obstacles obs = q.front();
            int x = obs.x;
            int y = obs.y;
            int rem = obs.rem_k;
            int moves = obs.moves;
            q.pop();
            if(x==n-1 && y==m-1) return moves;
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0 || ny<0 || nx==n || ny==m)  continue;
                if(grid[nx][ny] == 1){
                    if(rem == 0) continue;
                    else {
                        if(!dp[nx][ny][rem-1]){
                            q.push({nx, ny, rem-1, moves+1});
                            dp[nx][ny][rem-1] = 1;
                        }
                    }
                }else{
                    if(!dp[nx][ny][rem]){
                        q.push({nx, ny, rem, moves+1});
                        dp[nx][ny][rem] = 1;
                    }
                }
            }
        }
        return -1;
    }
};