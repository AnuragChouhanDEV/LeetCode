// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void reverse(int start, int end, vector<vector<int>>& matrix, int i) {
        while (start < end) {
            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < R; ++i)
            reverse(0,C-1, matrix, i);
    }
};