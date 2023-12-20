// https://leetcode.com/problems/image-smoother/description/?envType=daily-question&envId=2023-12-19

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        int dx[] = {1,1,1,0,-1,-1,-1,0};
        int dy[] = {1,0,-1,-1,-1,0,1,1};
        vector<vector<int>> res(m,vector<int>(n,0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = 0;
                int sum = 0;
                for (int x = max(0, i-1); x < min(m, i+2); ++x) {
                    for (int y = max(0, j-1); y < min(n, j+2); ++y) {
                        sum += img[x][y];
                        count += 1;
                    }
                }
                res[i][j] = sum/count;
            }
        }
        return res;
    }
};

/*
         

    -11     01    11
    -10     00    10
    -1-1    0-1   1-1
*/