// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>> mapp(n+1, {0,0});
        if (n == 1)
            return 1;
        for (int i = 0; i < trust.size(); ++i) {
            int person = trust[i][0];
            int to_trust = trust[i][1];

            mapp[person].first += 1;
            mapp[to_trust].second += 1;
        }
        for (int i = 0; i <= n; ++i) {
            if (mapp[i].first == 0 && mapp[i].second == n-1)
                return i;
        }
        return -1;
    }
};