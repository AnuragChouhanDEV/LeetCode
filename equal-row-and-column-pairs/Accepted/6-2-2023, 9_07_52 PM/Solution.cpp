// https://leetcode.com/problems/equal-row-and-column-pairs

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        unordered_map<string,int> ma;
        int res = 0;
        
        for (int j = 0; j < C;++j) {
            string s = "";
            for (int i = 0; i < R; ++i) {
                s += to_string(grid[i][j]);
                s += '#';
            }
            ma[s]++;
        }
        for(int i = 0; i < R; ++i) {
            string str = "";
            for (int j = 0; j < C;++j) {
                str += to_string(grid[i][j]);
                str += '#';
            }
            if (ma.find(str) != ma.end())
                res += ma[str];
        }
        return res;
    }
};