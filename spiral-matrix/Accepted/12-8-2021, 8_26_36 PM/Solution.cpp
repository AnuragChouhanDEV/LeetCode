// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bottom = matrix.size();
        int left = 0;
        int right = matrix[0].size();
        vector<int> res;
        while (left < right && top < bottom) {
            for (int i = left; i < right; ++i)
                res.push_back(matrix[top][i]);
            top++;
            
            for (int j = top; j < bottom; ++j)
                res.push_back(matrix[j][right-1]);
            right--;
            
            //cout << left << " " << right << " " << top << " " << bottom << endl;
            if (left >= right || top >= bottom)
                break;
//res.push_back(25);
            for (int i = right-1; i >= left; --i)
                res.push_back(matrix[bottom-1][i]);
            bottom--;
            
            
//res.push_back(20);
            for (int j = bottom-1; j >= top; --j)
                res.push_back(matrix[j][left]);
            left++;

        }
        return res;
    }
};