// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/?envType=daily-question&envId=2023-11-10

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        vector<int> res;
        unordered_map<int, vector<int>> v;
        unordered_map<int, bool> vis;
        int start;
        for (int i = 0; i < adjacentPairs.size(); ++i) {
            v[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            v[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        for (auto it: v) {
            if (it.second.size() == 1) {
                res.push_back(it.first);
                res.push_back(it.second[0]);
                break;
            }
        }
        while (res.size() < v.size()) {
            int le = res[res.size()-1];
            int lse = res[res.size()-2];
            vector<int> ne = v[le];
            if (lse != ne[0]) {
                res.push_back(ne[0]);
            } else {
                res.push_back(ne[1]);
            }
        }
#if 0
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (vis[curr]) continue;
            vis[curr] = true;
            for (auto it:v[curr]) {
                if (vis[it]) continue;
                res.push_back(it);
                q.push(it);
            }
        }
#endif
        return res;
    }
};

/*
[[4,-10],[-1,3],[4,-3],[-3,3]]

4 -> -10 -> -3
-10 -> 4
-1 -> 3
3 -> -1 -> -3
-3 -> 4 -> 3

-1 -> 3 -> -3 -> 4 -> -10

*/

