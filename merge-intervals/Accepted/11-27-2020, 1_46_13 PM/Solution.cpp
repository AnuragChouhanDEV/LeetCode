// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged_intervals;
        if (intervals.size() == 0)
            return merged_intervals;
        sort(intervals.begin(), intervals.end());
        vector<int > tmp = intervals[0];
        
        for (auto itr: intervals) {
            if (itr[0] <= tmp[1])
                tmp[1] = max(itr[1], tmp[1]);
            else {
                merged_intervals.push_back(tmp);
                tmp = itr;
            }
        }
        merged_intervals.push_back(tmp);
        return merged_intervals;
    }
};