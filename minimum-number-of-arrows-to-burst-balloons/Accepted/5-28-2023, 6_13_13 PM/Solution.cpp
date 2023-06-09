// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<int> tmp(points[0].begin(), points[0].end());
        stack<vector<int>> s;
        s.push(tmp);
        for (int i = 1; i < points.size(); ++i) {
            vector<int> a = s.top();
            vector<int> x;
            if (a[1] >= points[i][0]) {
                x.push_back(max(a[0], points[i][0]));
                x.push_back(min(a[1], points[i][1]));
                s.pop();
                s.push(x);
            } else {
                s.push(points[i]);
            }
        }
        return s.size();
    }
};