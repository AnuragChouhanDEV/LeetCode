// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int R = matrix.size();
        if (R == 0) {
            return {};
        }
        int C = matrix[0].size();
        int i = 0;
        int j = 0;
        while (i < R && j < C) {
            for (int k = j; k < C; ++k) {
                res.push_back(matrix[i][k]);
            }++i;
            for (int k = i; k < R; ++k) {
                res.push_back(matrix[k][C-1]);
            }--C;
            if (i < R) {
                for (int k = C-1; k >=j; --k) {
                    res.push_back(matrix[R-1][k]);
                }
                R--;
            }
            if (j < C) {
                for (int k = R-1; k >= i; --k) {
                    res.push_back(matrix[k][j]);
                }
                j++;
            }
        }
        return res;
    }
};