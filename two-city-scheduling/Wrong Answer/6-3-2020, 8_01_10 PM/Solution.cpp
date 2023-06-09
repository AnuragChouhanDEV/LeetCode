// https://leetcode.com/problems/two-city-scheduling

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int tot = 0;
        int cnt_a = 0;
        int cnt_b = 0;
        for (int i = 0; i < costs.size();++i) {
            if (cnt_a == costs.size()/2) {
                tot += costs[i][1];
            }
            else if (cnt_b == costs.size()/2) {
                tot += costs[i][0];
            }
            else {
                if (costs[i][0] <= costs[i][1]) {
                    tot += costs[i][0];
                    cnt_a++;
                }
                else {
                    tot += costs[i][1];
                    cnt_b++;
                }
            }
        }
        return tot;
    }
};