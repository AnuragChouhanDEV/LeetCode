// https://leetcode.com/problems/dota2-senate

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R;
        queue<int> D;

        for (int i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R')
                R.push(i);
            else
                D.push(i);
        }
        while (!R.empty() && !D.empty()) {
            int r = R.front();
            int d = D.front();
            R.pop();
            D.pop();
            if (r < d) {
                R.push(r+senate.size());
            } else {
                D.push(d+senate.size());
            }
        }
        return !R.empty() ? "Radiant":"Dire";
    }
};