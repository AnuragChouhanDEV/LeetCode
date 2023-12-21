// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/?envType=daily-question&envId=2023-12-21

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> x; 
        for (const auto& point : points) x.insert(point[0]);
        
        int res = 0;
        int prevX = INT_MIN;
        
        for (int pt : x) {
            if (prevX != INT_MIN) res = max(res, pt - prevX);
            prevX = pt;
        }
        return res;
#if 0
        sort(points.begin(), points.end());
        int maxi = INT_MIN;
        for (int i = 1; i < points.size(); ++i) {
            maxi = max(maxi, points[i][0] - points[i-1][0]);
        }
        return maxi;
#endif
    }
};