// https://leetcode.com/problems/spiral-matrix-ii

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,1));
        int R = n;
        int C = n;
        int i = 0;
        int j = 0;
        int k = 1;

        while (i < R && j < C && k <= n*n) {
            // keep i increase j from 0, i++;
            for (int x = j; x < C && k <= n*n; ++x) {
                matrix[i][x] = k++;
            } i++;
            
            if (k > n*n) return matrix;
            // keep j increase i from i, j--;
            for (int x = i; x < R && k <= n*n; ++x) {
                matrix[x][C-1] = k++;
            } C--;
            if (k > n*n) return matrix;
            // keep i decrease j from last, i--;
            for (int x = C-1; x >= j && k <= n*n; --x) {
                matrix[R-1][x] = k++;
            } R--;
            if (k > n*n) return matrix;
            // keep j decrease i from current, j++;
            for (int x = R-1; x >= i && k <= n*n; --x) {
                matrix[x][j] = k++;
            } j++;
            if (k > n*n) return matrix;
            //cout << "i " << i << " R " << R << " j " << j << " C " << C << endl;

        }
        return matrix;
    }
};