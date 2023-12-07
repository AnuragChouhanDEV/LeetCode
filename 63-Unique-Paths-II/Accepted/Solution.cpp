// https://leetcode.com/problems/unique-paths-ii/description/?envType=daily-question&envId=2023-12-07

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0]) return 0;
        vector<vector<int>> vec(m, vector<int>(n,0));
        for (int i = 0; i < m; ++i) {
          if (obstacleGrid[i][0] == 0) {
            vec[i][0] = 1;
          } else {
            break;
          }
        }
        for (int i = 0; i < n; ++i) {
          if (obstacleGrid[0][i] == 0) {
            vec[0][i] = 1;
          } else {
            break;
          }
        }
        
        for (int i = 1; i < m; ++i) {
          for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 1) continue;
            vec[i][j] = vec[i-1][j]+vec[i][j-1];
          }
        }
        #if 0
        for (int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
            cout << vec[i][j] << " ";
          }
          cout << endl;
        }
        #endif
        return vec[m-1][n-1];
    }
};