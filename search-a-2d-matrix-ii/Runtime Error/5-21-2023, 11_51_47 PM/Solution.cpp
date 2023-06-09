// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = matrix.size();
        int C = matrix[0].size();
        if (target > matrix[R-1][C-1]) return false;
        int row = 0;
        int col = 0;
        while (row < R && col < C) {
            if (target == matrix[row][col]) return true;
            if (target < matrix[row][col]) break;
            row++;col++;
        }
        cout << row << " " <<col << endl;
        for (int i = row; i >= 0; --i) if (target == matrix[i][col]) return true;
        for (int j = col; j >= 0; --j) if (target == matrix[row][j]) return true;
        return false;
    }
};