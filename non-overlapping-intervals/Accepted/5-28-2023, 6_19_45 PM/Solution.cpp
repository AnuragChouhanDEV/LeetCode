// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(), intervals.end());
        stack<vector<int>> s;
        s.push(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> a = s.top();
            vector<int> x;
            if (a[1] > intervals[i][0]) {
                x.push_back(max(a[0], intervals[i][0]));
                x.push_back(min(a[1], intervals[i][1]));
                s.pop();
                s.push(x);
            } else {
                s.push(intervals[i]);
            }
        }
        return intervals.size()-s.size();
    }
};