// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int R = coordinates.size();
        sort(coordinates.begin(), coordinates.end());
        int C = coordinates[0].size();
        int x1 = (coordinates[0][0]);
        int y1 = (coordinates[0][1]);
        int x2 = (coordinates[R-1][0]);
        int y2 = (coordinates[R-1][1]);
        //if (x2-x1 <= 0) return false;
        double slope = ((y2-y1)/((x2-x1)?(x2-x1):100000));
        for (int i = 1; i < R; ++i) {
            int x3 = (coordinates[i-1][0]);
            int y3 = (coordinates[i-1][1]);
            int x4 = (coordinates[i][0]);
            int y4 = (coordinates[i][1]);
            //if (x4-x3 <= 0) return false;
            if (!(slope == (double)((y4-y3)/((x4-x3)?(x4-x3):100000)))) return false;
        }
        return true;
    }
};