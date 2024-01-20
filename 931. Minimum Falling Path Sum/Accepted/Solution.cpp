// https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int sum = INT_MAX;
        int R = matrix.size();
        int C = matrix[0].size();

        for (int i = 1; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                int i_1j_1 = j-1 >= 0 ? matrix[i-1][j-1]: 20000000;
                int i_1j0 = matrix[i-1][j];
                int i_1j1 = j+1 < C ? matrix[i-1][j+1] : 20000000;
                int local_min = min(i_1j_1, min(i_1j0, i_1j1));
                matrix[i][j] = matrix[i][j] + local_min;
                //cout << matrix[i][j] << " "<< local_min<<endl;
                if (i == R-1) {
                    sum = min(sum, matrix[i][j]);
                    //cout << sum << endl;
                }
            }
        }
        if (sum == INT_MAX || R == 1) {
            for (int j = 0; j < C; ++j) {
                sum = min(sum, matrix[0][j]);
            }
        }
        return sum;
    }
#if 0
    int dfs(vector<vector<int>>& matrix, int j, int i, int R, int C, vector<vector<int>> &dp) {
        if (j >= C || j < 0) return INT_MAX - 10000;
        if (i >= R || i < 0 ) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int i1j_1 = dfs(matrix, j-1, i+1, R, C, dp);
        int i1j0 = dfs(matrix, j, i+1, R, C, dp);
        int i1j1 = dfs(matrix, j+1, i+1, R, C, dp);
        return dp[i][j] = matrix[i][j] + min(i1j_1, min(i1j0, i1j1));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int sum = INT_MAX;
        int R = matrix.size();
        int C = matrix[0].size();
        vector<vector<int>> dp(R,vector<int>(C, -1));
        for (int j = 0; j < C; ++j) {
            int local_sum = dfs(matrix, j, 0, R, C, dp);
            sum = min(sum, local_sum);
        }
        return sum;
    }
#endif
};

/*
2 1 3
6 5 4
7 8 9

2   1 3
7   6 5
13 13 14 
*/