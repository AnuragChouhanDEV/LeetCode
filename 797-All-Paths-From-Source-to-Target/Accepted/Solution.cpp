// https://leetcode.com/problems/all-paths-from-source-to-target/description/

class Solution {
public:
    void dfs(vector<vector<int>> &adj, int source, int dest, vector<vector<int>> &res, vector<int> &v) {
        if (source == dest) {
            v.push_back(dest);
            res.push_back(v);
            v.pop_back();
            return;
        }
        for (auto it:adj[source]) {
            v.push_back(source);
            dfs(adj, it, dest, res, v);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                adj[i].push_back(graph[i][j]);
            }
        }
        int source = 0;
        int dest = n-1;

        vector<vector<int>> res;
        vector<int> vis(n, 0);
        vector<int> v;

        dfs(adj, source, dest, res, v);
        return res;
    }
};

/*
0 -> 1 2
1 -> 3
2 -> 3
3 -> 0


*/