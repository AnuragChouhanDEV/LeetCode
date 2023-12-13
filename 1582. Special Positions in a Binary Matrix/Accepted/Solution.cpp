// https://leetcode.com/problems/special-positions-in-a-binary-matrix/

class Solution {
public:
    int chk_col(vector<vector<int>>& mat, int i, int idx) {
        for (int j = 0; j < mat.size(); ++j) {
            if (mat[j][idx] && j!= i)
                return false;
        }
        return true;
    }
    int chk_row(vector<vector<int>>& mat, int i) {
        int idx = -1;
        for (int j = 0; j < mat[i].size(); ++j) {
            if (mat[i][j]) {
                if (idx != -1) return -1;
                else idx = j;
            }
        }
        return idx;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            int idx = chk_row(mat, i);
            if (idx >= 0 && chk_col(mat, i, idx))
                count++;
        }
        return count;
    }
#if 0
    bool check_all(vector<vector<int>>& mat, int i, int j, int m, int n) {
        int di[4] = {1, -1, 0, 0};
        int dj[4] = {0, 0, 1, -1};
        for (int x = 0; x < 4; ++x) {
            int ni = i+di[x];
            int nj = j+dj[x];
            while (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                if (mat[ni][nj])
                    return false;
                ni = ni+di[x];
                nj = nj+dj[x];
            }
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) {
                    if (check_all(mat, i, j, m, n)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
#endif
};