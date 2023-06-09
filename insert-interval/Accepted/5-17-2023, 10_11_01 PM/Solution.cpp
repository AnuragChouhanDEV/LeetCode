// https://leetcode.com/problems/insert-interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int size = intervals.size();
        int ptr = 0;
        vector<int> tmp = newInterval;
        while (ptr < size && intervals[ptr][1] < newInterval[0]) {
            res.push_back(intervals[ptr]); ptr++;
        }

        while (ptr < size && intervals[ptr][0] <= newInterval[1]) {
            tmp[0] = min(tmp[0], intervals[ptr][0]);
            tmp[1] = max(tmp[1], intervals[ptr][1]);
            ptr++;
        }
        res.push_back(tmp);
        while(ptr < size) {
            res.push_back(intervals[ptr]); ptr++;
        }
        return res;
    }
};