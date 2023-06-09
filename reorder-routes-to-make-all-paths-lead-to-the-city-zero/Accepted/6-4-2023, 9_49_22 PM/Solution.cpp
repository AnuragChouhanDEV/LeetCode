// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

class Solution {
public:
    vector<pair<int,int>> res[50005];
    int ans = 0;
    void dfs(int start, int parent) {
        for (pair<int,int> a : res[start]) {
            if (a.first == parent) continue;
            else {
                ans += a.second;
                dfs(a.first, start);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        for (auto a:connections) {
            res[a[0]].push_back({a[1], 1});
            res[a[1]].push_back({a[0], 0});
        }
        dfs(0,0);
        return ans;
    }
};