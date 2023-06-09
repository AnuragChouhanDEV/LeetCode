// https://leetcode.com/problems/count-square-submatrices-with-all-ones

class Solution {
    int min (int a, int b) {
        return a > b ? b : a;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (!row)
            return 0;
        int col = matrix[0].size();
        int sum = 0;
        
        vector<vector<int> > vec( row+1 , vector<int> (col+1));
        for (int i = 0; i < row+1; ++i) {
            for (int j = 0; j < col+1; ++j) {
                if (i == 0 || j == 0) {
                    vec[i][j] = 0;
                } else if (i == 1 || j == 1) {
                    vec[i][j] = matrix[i-1][j-1];
                } else {
                    if (matrix[i-1][j-1]) {
                        vec[i][j] = 1 + min(min(vec[i-1][j],vec[i-1][j-1]), vec[i][j-1]);
                    } else {
                        vec[i][j] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < row+1; ++i) {
            for (int j = 0; j < col+1; ++j) {
                sum +=vec[i][j];
                //cout << vec[i][j] << " ";
            }
            //cout << endl;
        }
        //cout << sum << endl;
        return sum;
    }
};