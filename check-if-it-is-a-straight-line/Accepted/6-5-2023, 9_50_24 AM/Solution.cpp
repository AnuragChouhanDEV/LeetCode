// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution {
public:
    double get_slope(vector<vector<int>>& coordinates, int x1, int  y1, int x2, int y2) {
        if (x1 == x2) return 100000;
        return (y2-y1)/(x2-x1);
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int R = coordinates.size();
        //sort(coordinates.begin(), coordinates.end());
        //int C = coordinates[0].size();
        //int x1 = (coordinates[0][0]);
        //int y1 = (coordinates[0][1]);
        //int x2 = (coordinates[R-1][0]);
        //int y2 = (coordinates[R-1][1]);
        //if (x2-x1 <= 0) return false;
        double slope = get_slope(coordinates, coordinates[0][0], coordinates[0][1], coordinates[R-1][0], coordinates[R-1][1]);
        for (int i = 1; i < R; ++i) {
            int x3 = (coordinates[i-1][0]);
            int y3 = (coordinates[i-1][1]);
            int x4 = (coordinates[i][0]);
            int y4 = (coordinates[i][1]);
            //if (x4-x3 <= 0) return false;
            if (!(slope == get_slope(coordinates, coordinates[i-1][0], coordinates[i-1][1], coordinates[i][0], coordinates[i][1]))) return false;
        }
        return true;
    }
};