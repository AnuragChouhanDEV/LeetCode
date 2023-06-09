// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

class Solution {
public:
    bool is_safe(int x, int y, int m, int n, vector<vector<char>>& maze) {
        return (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.');
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int min_count = 1;
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        maze[entrance[0]][entrance[1]]='+';
        while(!q.empty()) {
            int size = q.size();
            for (int j = 0; j < size; ++j) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int newx = x+dx[i];
                    int newy = y+dy[i];
                    if (!is_safe(newx,newy,m,n,maze)) {
                        continue;
                    } 
                    else if (newx == 0 || newx == m-1 || newy == 0 || newy == n-1)
                        return min_count;
                    maze[newx][newy] = '+';
                    q.push({newx,newy});
                }
            }
            min_count++;
        }
        return -1;
    }
};