// https://leetcode.com/problems/triangle

class Solution {
public:
    void min_total(vector<vector<int>> triangle, int i, int j, int size, int &sum, int &min1) {
        if (i == size || j == size )
            return;
        sum += triangle[i][j];
        min_total(triangle, i+1, j, size, sum, min1);
        if (i == size-1)
            min1 = min(sum, min1);
        sum -= triangle[i][j];
        min_total(triangle, i, j+1, size, sum, min1);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        for (int i = 1; i < row; ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    triangle[i][j] += triangle[i-1][j];
                }
                else if (j == triangle[i].size()-1) {
                    triangle[i][j] += triangle[i-1][j-1];
                }
                else {
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                }   
            }
        }
        int res = triangle[row-1][0];
        for (int i = 1; i < triangle[row-1].size(); ++i) {
            res = min(res, triangle[row-1][i]);
        }
        return res;
    }
};