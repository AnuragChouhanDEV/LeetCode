// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    void helper(vector<vector<int>>& isConnected, int i, int j) {
        isConnected[i][j] = 0;
        for (int k = 0; k < isConnected.size(); ++k) {
            if (isConnected[j][k])
                helper(isConnected, j, k);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int max_province = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j]) {
                    helper(isConnected, i, j);
                    max_province++;
                }
            }
        }
        return max_province;
    }
};