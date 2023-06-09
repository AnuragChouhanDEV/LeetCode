// https://leetcode.com/problems/insert-interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = intervals.size();
        //intervals.push_back(newInterval);
        //sort(intervals.begin(), intervals.end());
        int id1 = 0;
        int id2 = 0;
        int start = 0;
        int count = 0;
        #if 1
        for (int i = 0; i < len - 1;++i) {
            if (start) {
                intervals[i][0] = -1;
                count++;
            }
            if (intervals[i][1] >= newInterval[0]) {
                start = 1;
                id1 = i;
                
            }
            if (intervals[i][1] >= newInterval[1]) {
                id2 = i;
                start = 0;
                
            }
            if (start) {
                intervals[i][1] = -1;
            }
            cout << intervals[i][0] << " " << intervals[i][1] << " " << id1 << " " << id2 << " "<<start << endl;
        }
        sort(intervals.begin(), intervals.end());
        #endif
        while(--count)
            intervals.erase(intervals.begin());
        for (int i = 0; i < len - 1;++i) {
            if (intervals[i][0] == -1) {
                id1 = intervals[i][1];
                intervals[i][1] = -1;
            }
            if (intervals[i][1] == -1) {
                intervals[i][1] = id1;
            }
        }
        intervals.erase(intervals.begin());
        return intervals;
    }
};