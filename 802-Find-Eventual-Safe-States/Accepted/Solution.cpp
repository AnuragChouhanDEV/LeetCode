// https://leetcode.com/problems/find-eventual-safe-states/description/

class Solution {
public:
    
    bool dfs(vector<vector<int>> &adj, int node,vector<int> &vis,vector<int> &pvis) {
        vis[node] = 1;
        pvis[node] = 1;
        for (auto n:adj[node]) {
            if (!vis[n]) {
                if (dfs(adj, n, vis, pvis)) {
                    return true;
                }
            }
            else if (pvis[n]) {
                return true;
            }
        }
        pvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis, pvis;
        vis.resize(n,0);
        pvis.resize(n,0);
        //chk.resize(n,0);
        vector<vector<int>> adj(n);
        vector<int> res;
        int i = 0;
        for (auto it:graph) {
            for (auto x:it) {
                adj[i].push_back(x);
            }
            ++i;
        }
        for (i = 0; i < n; ++i) {
            if (!vis[i])
                dfs(adj, i, vis, pvis);
        }
        
        for (int j = 0; j < pvis.size(); ++j) {
            if (!pvis[j])
                res.push_back(j);
        }
        return res;
    }
};
/*

                        0                           6
              1                  2
        2       3                   5
                    0                   4   

*/