// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //cout << intervals.size() << endl;
        //cout << intervals[0].size() << endl;
        int i = 0, j = 0;
        while (i < intervals.size() - 1) {
            if (intervals[i][j+1] >= intervals[i+1][j])
                if (intervals[i][j+1] <= intervals[i+1][j+1]) {
                    intervals[i][j+1] = intervals[i+1][j+1];
                    if (intervals[i][j] >= intervals[i+1][j])
                        intervals[i][j] = intervals[i+1][j];
                    ++i;
                    intervals.erase(intervals.begin()+i);
                }
            ++i;
        }
        return intervals;
    }
};