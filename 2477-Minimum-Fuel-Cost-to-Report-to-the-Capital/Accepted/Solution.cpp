// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/

class Solution {
public:
    long long dfs(vector<vector<int>> &adj, int source, vector<int> &vis, long long &res, int seats) {
        vis[source] = 1;

        long long cnt = 1;
        for (auto it: adj[source]) {
            if (!vis[it])
                cnt += dfs(adj, it, vis, res, seats);
        }
        long long x = cnt/seats;
        if (cnt % seats) x++;
        if (source != 0) res += x;
        return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        if (n == 0) return 0;
        long long res = 0;
        vector<int> vis(n+1, 0);
        vector<vector<int>> adj(n+1);
        int source = 0;

        for (int i = 0; i < roads.size(); ++i) {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        dfs(adj, source, vis, res, seats);
        return res;
    }
};

/*
0 -> 1 4 5
3 -> 1 2
1 -> 3 0
2 -> 3
4 -> 0 6
5 -> 0
6 -> 4



*/