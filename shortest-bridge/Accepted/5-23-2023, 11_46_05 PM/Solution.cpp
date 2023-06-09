// https://leetcode.com/problems/shortest-bridge

class Solution {
public:
    const int dx[4]={-1,1,0,0};
    const int dy[4]={0,0,-1,1};
    bool  bound(int i,int j,int r,int c) {
          return (i<r && j<c && i>=0 && j>=0);
    }
    
    void dfs(int i, int j, int R, int C, int set, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= R || j >= C || grid[i][j] != 1)
            return;
        grid[i][j] = set;
        dfs(i+1, j, R, C, set, grid);
        dfs(i-1, j, R, C, set, grid);
        dfs(i, j+1, R, C, set, grid);
        dfs(i, j-1, R, C, set, grid);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        // set one island to 2
        int R = grid.size();
        int C = grid[0].size();
        int set = 2;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C;++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j, R, C, set, grid);
                    set = 3;
                    break;
                }
            }
            if (set == 3) break;
        }
        
        int res = INT_MAX;
        queue<pair<int,int>>q;
        // start bfs from 2 to 1,
        //get the new islands in queue
        for(int i=0;i<R;++i) {
            for(int j=0;j<C;++j) {
                if(grid[i][j]==2) {
                    q.push({i,j});       
                }
            }
        }
        int change=0;
 
        //find the nearest distance to the 1 island from the island 2 
        while(!q.empty()) {
            ++change;
            int sz=q.size();
            while(sz--) {
               auto node=q.front();
               q.pop();
                //4 directions
               for(int x=0;x < 4;++x) {
                    int new_i = node.first  + dx[x];
                    int new_j = node.second + dy[x];
 
                    if(bound(new_i,new_j,R,C) ) {
                        if( grid[new_i][new_j]==0){
                            grid[new_i][new_j]=2;
                            q.push({new_i,new_j});
                        }
                        if(grid[new_i][new_j]==1)
                            return change-1; 
                    }  
                }     
            }
        }
        return 0;
    }
};