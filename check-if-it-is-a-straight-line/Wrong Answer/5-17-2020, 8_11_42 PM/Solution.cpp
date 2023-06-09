// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int points = coordinates.size();
        int xdiff = abs(abs(coordinates[1][0])-abs(coordinates[0][0]));
        int ydiff = abs(abs(coordinates[1][1])-abs(coordinates[0][1]));
        int curr_xdiff,curr_ydiff;
        
        for(int i=2;i<points;++i)
        {
            curr_xdiff = abs(abs(coordinates[i][0])-abs(coordinates[i-1][0]));
            curr_ydiff = abs(abs(coordinates[i][1])-abs(coordinates[i-1][1]));
            if(ydiff*curr_xdiff != xdiff*curr_ydiff)
                return false;
        }
        return true;
    }
};