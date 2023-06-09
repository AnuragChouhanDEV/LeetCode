// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix.size()-1;
        while (row <= matrix[0].size()-1 && col >= 0) {
            if (matrix[row][col] > target)
                col--;
            else if (matrix[row][col] < target)
                row++;
            else
                return true;
        }
        return false;
    }
};