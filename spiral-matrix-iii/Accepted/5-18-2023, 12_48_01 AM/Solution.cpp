// https://leetcode.com/problems/spiral-matrix-iii

class Solution {
public:
    bool in_bound(int rows, int cols, int rStart, int cStart) {
        return (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols);
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int total_count = rows*cols;
        int steps = 1;
        //res.push_back({rStart,cStart});

        while (rStart < total_count && cStart < total_count && rStart > -1*total_count && cStart > -1*total_count) {

            for (int i = 0; i < steps; ++i) {
                if (in_bound(rows,cols, rStart, cStart)) res.push_back({rStart,cStart});
                cStart++;
            }
            for (int i = 0; i < steps; ++i) {
                if (in_bound(rows,cols, rStart, cStart)) res.push_back({rStart,cStart});
                rStart++;
            }
            steps++;
            for (int i = 0; i < steps; ++i) {
                if (in_bound(rows,cols, rStart, cStart)) res.push_back({rStart,cStart});
                cStart--;
            }
            for (int i = 0; i < steps; ++i) {
                if (in_bound(rows,cols, rStart, cStart)) res.push_back({rStart,cStart});
                rStart--;
            }
            steps++;
        }
        return res;
    }
};