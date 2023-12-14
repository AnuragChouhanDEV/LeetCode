// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row(m,0);
        vector<int> col(n,0);
        for (int i = 0; i < m; ++i) {
            int sum_one = 0;
            int sum_zero = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    sum_one++;
                } else {
                    sum_zero++;
                }
            }
            row[i] = sum_one-sum_zero;
        }
        for (int j = 0; j < n; ++j) {
            int sum_one = 0;
            int sum_zero = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j]) {
                    sum_one++;
                } else {
                    sum_zero++;
                }
            }
            col[j] = sum_one-sum_zero;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                grid[i][j] = row[i]+col[j];
            }
        }
        return grid;
    }
};

/*
2-1  row 0
1-2  col 0

2-1  row 1
1-2  col 1

1-2  row 2
3-0  col 2
*/