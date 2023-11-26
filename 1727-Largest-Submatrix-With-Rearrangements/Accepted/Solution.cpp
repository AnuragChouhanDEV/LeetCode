// https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/?envType=daily-question&envId=2023-11-26

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<pair<int,int>> ph;
        int ans = 0;

        for(int row = 0; row < m; ++row) {
            vector<pair<int,int>> ht;
            vector<bool> seen(n,false);

            for (auto [h,col]:ph) {
                if (matrix[row][col]) {
                    ht.push_back({h+1, col});
                    seen[col] = true;
                }
            }
            for (int col = 0; col < n; ++col) {
                if (seen[col] == false && matrix[row][col])
                    ht.push_back({1,col});
            }
            for (int i = 0; i <ht.size(); ++i)
                ans = max(ans, ht[i].first * (i+1));
            ph = ht;
        }
        return ans;
    }
};
/*
2 3 1
1 2 3
3 4 3

0 0 1 1 1
0 0 3 2 1

1 1 2

*/