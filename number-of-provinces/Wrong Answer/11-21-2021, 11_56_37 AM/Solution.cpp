// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int row = isConnected.size();
        int col = row;
        int provinces = row * 2;
        for(int i = 0; i < row; ++i) {
            for (int j = i; j < col; ++j) {
                if (isConnected[i][j] == 1)
                    provinces--;
            }
        }
        return provinces;
    }
};