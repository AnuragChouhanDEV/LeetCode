// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> leftarray(heights.size(), 0);
        vector<int> rightarray(heights.size(), 0);
        stack<int> st_idx;
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (!st_idx.empty() && heights[st_idx.top()] > heights[i])
                st_idx.pop();
            if (st_idx.empty())
                leftarray[i] = 0;
            else
                leftarray[i] = st_idx.top() + 1;
            st_idx.push(i);
        }
        while (!st_idx.empty())
            st_idx.pop();
        for (int i = heights.size()-1; i >= 0; --i) {
            if (!st_idx.empty() && heights[st_idx.top()] > heights[i])
                st_idx.pop();
            if (st_idx.empty())
                rightarray[i] = heights.size()-1;
            else
                rightarray[i] = st_idx.top() - 1;
            st_idx.push(i);
        }
        for (int i = 0; i < heights.size(); ++i) {
            res = max(res, (rightarray[i] - leftarray[i] + 1) * heights[i]);
        }
        return res;
    }
};