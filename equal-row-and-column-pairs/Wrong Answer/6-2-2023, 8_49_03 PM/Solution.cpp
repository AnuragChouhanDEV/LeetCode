// https://leetcode.com/problems/equal-row-and-column-pairs

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        unordered_map<int, pair<int,vector<int>>> ma;
        int res = 0;
        
        for (int j = 0; j < C;++j) {
            vector<int> v;
            for (int i = 0; i < R; ++i) {
                v.push_back(grid[i][j]);
            }
            if (ma.find(grid[0][j]) != ma.end()) {
                if (v == ma[grid[0][j]].second) {
                    ma[grid[0][j]].first++;
                }
            } else
                ma[grid[0][j]]={1,v};
        }
        for(int i = 0; i < R; ++i) {
            if (ma.find(grid[i][0]) != ma.end())
                if (ma[grid[i][0]].second == grid[i])
                    res += ma[grid[i][0]].first;
        }
        return res;
    }
};