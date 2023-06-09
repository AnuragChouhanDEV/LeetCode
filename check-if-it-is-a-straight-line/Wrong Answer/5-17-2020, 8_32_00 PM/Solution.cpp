// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        map<int,int> x_cord;
        map<int,int> y_cord;
        
        int points = coordinates.size();
        int xdiff = abs(coordinates[1][0]-coordinates[0][0]);
        int ydiff = abs(coordinates[1][1]-coordinates[0][1]);
        cout << xdiff << " " << ydiff << endl;
        int curr_xdiff,curr_ydiff;
        x_cord[coordinates[0][0]]++;
        x_cord[coordinates[1][0]]++;
        y_cord[coordinates[0][1]]++;
        y_cord[coordinates[1][1]]++;
        
        for(int i=2;i<points;++i)
        {
            curr_xdiff = abs(coordinates[i][0]-coordinates[i-1][0]);
            curr_ydiff = abs(coordinates[i][1]-coordinates[i-1][1]);
            x_cord[coordinates[i][0]]++;
            y_cord[coordinates[i][1]]++;
            if (x_cord[coordinates[i][0]] > 1 || y_cord[coordinates[i][1]] > 1)
                return false;
            cout << curr_xdiff << " " << curr_ydiff << endl;
            if(ydiff*curr_xdiff != xdiff*curr_ydiff)
                return false;
        }
        return true;
    }
};