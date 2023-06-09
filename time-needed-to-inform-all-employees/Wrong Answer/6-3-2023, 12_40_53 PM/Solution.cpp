// https://leetcode.com/problems/time-needed-to-inform-all-employees

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int minutes = informTime[headID];
        queue<pair<int,int>> q;

        q.push({headID,informTime[headID]});
        while (!q.empty()) {
            pair<int,int> p = q.front();
            //minutes += p.second;
            int maxi = 0;
            int idx = p.first;
            q.pop();

            for (int i = 0; i < manager.size(); ++i) {
                if (idx == manager[i]) {
                    maxi = max(maxi, informTime[i]);
                    q.push({i, informTime[i]});
                }
            }
            minutes+=maxi;
        }
        return minutes;
    }
};