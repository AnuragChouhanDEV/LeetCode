// https://leetcode.com/problems/unique-paths

class Solution {
public:
#if 0
    int uniquePaths(int m, int n) {
        if (m < 0 || n < 0) return 0;
        if (m == 1 && n == 1) return 1;
        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
#else
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n,1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                v[i][j] = v[i-1][j]+v[i][j-1];
            }
        }
        return v[m-1][n-1];
    }
#endif
};
