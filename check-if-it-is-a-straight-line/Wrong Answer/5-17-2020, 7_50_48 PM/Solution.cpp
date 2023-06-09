// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int size = coordinates.size();
        int x_diff = coordinates[1][0]-coordinates[0][0];
        int y_diff = coordinates[1][1]-coordinates[0][1];
        //cout << coordinates[0][0] << " " << coordinates[0][1] << endl;
        //cout << coordinates[1][0] << " " << coordinates[1][1] << endl;
        //cout << coordinates[2][0] << " " << coordinates[2][1] << endl;
        //cout << coordinates[3][0] << " " << coordinates[3][1] << endl;
        for (int i = 1; i < size; ++i) {
            if ((x_diff != (coordinates[i][0]-coordinates[i-1][0])) && (y_diff != (coordinates[i][1]-coordinates[i-1][1])))
                return false;
        }
        return true;
    }
};