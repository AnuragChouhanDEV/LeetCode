// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i = 1; i < n; ++i) {
            bool flag = false;
            int k = i, j = 0;
            while (j < n && k < n) {
                if (isConnected[k][j])
                    flag = true;
                ++j;++k;
            }
            if (flag)
                n--;
        }
        return n;
    }
};