// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));
        bool flag = false;
        for (int i = 0; i < row; ++i) {
            if (flag || obstacleGrid[0][i] == 1) {
                flag = true;
                dp[0][i] = 0;
            } else {
                dp[0][i] = 1;
            }
        }
        flag = false;
        for (int i = 0; i < col; ++i) {
            if (flag || obstacleGrid[i][0] == 1) {
                flag = true;
                dp[i][0] = 0;
            } else {
                dp[i][0] = 1;
            }
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    //cout << "here " << i << " " << j <<endl;
                    continue;
                }
                //cout << "here " << i << " " << j <<endl;
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[row-1][col-1];
    }
};