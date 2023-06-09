// https://leetcode.com/problems/two-city-scheduling

class Solution {
    static bool sortcol( const vector<int>& v1, const vector<int>& v2 ) { 
        return v1[0] - v1[1] < v2[0] - v2[1]; 
    } 
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int tot = 0;
        int cnt_a = 0;
        int cnt_b = 0;
        sort(costs.begin(), costs.end(),sortcol);
        for (int i = 0; i < costs.size()/2;++i) {
            //cout << costs[i][1] << endl;
            tot += costs[i][0];
        }
        for (int i = costs.size()/2; i < costs.size();++i) {
            //cout << costs[i][1] << endl;
            tot += costs[i][1];
        }
        return tot;
    }
};