// https://leetcode.com/problems/count-the-number-of-complete-components/description/

class Solution {
public:
    pair<int, int> dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[node] = true;
        int vertices = 1;
        int edges = adj[node].size();
        cout << node << endl;
        for (auto it:adj[node]) {
            if (!visited[it]) {
                pair<int, int> p = dfs(it, adj, visited);
                vertices += p.first;
                edges += p.second;
            }
        }
        return {vertices, edges};
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        int res = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                pair<int, int> p = dfs(i, adj, visited);
                int node = p.first;
                int edges = p.second;
                if ((node * (node-1)) == edges)
                    res++;
            }
        }
        return res;
    }
};

/*
0 -> 1 2
1 -> 0 2
2 -> 0 1
3 -> 4
4 -> 3

2 2 2 1 1 0

2 2 2 2 1 1

  0 1 2 3 4 5
0 1 1 1
1 1 1 1
2 1 1 1
3       1 1
4       1 1
5           1
*/