// https://leetcode.com/problems/insert-interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = intervals.size();
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int count = 0;
        #if 1
        for (int i = 0; i < len - 1;++i) {
            if (intervals[i][1] >= intervals[i+1][0])
                //if (intervals[i][1] >= intervals[i+1][1]) {
                    intervals[i][1] = intervals[i+1][1];
                    intervals[i+1][0] = -1;
                    intervals[i+1][1] = -1;
                    sort(intervals.begin(), intervals.end());
                    count++;
                    //--i;
                //}
            cout << intervals[i][0] << endl;
        }
        #endif
        while(count--)
            intervals.erase(intervals.begin());
        return intervals;
    }
};