// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int R = coordinates.size();
        int C = coordinates[0].size();
        int x1 = abs(coordinates[0][0]);
        int y1 = abs(coordinates[0][1]);
        int x2 = abs(coordinates[R-1][0]);
        int y2 = abs(coordinates[R-1][1]);
        double slope = (y2-y1)/(x2-x1);
        for (int i = 1; i < R; ++i) {
            int x3 = abs(coordinates[i-1][0]);
            int y3 = abs(coordinates[i-1][1]);
            int x4 = abs(coordinates[i][0]);
            int y4 = abs(coordinates[i][1]);
            if (!(slope == (y4-y3)/(x4-x3))) return false;
        }
        return true;
    }
};