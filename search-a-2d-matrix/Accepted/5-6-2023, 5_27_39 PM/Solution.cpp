// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = matrix.size();
        if (R == 0) {return false;}
        int C = matrix[0].size();
        int i = 0;
        int j = C-1;
        while (i < R && j >= 0) {
            if (target == matrix[i][j])
                return true;
            else if (target < matrix[i][j]) {
                j--;
            } else
                i++;
        }
        return false;
    }
};