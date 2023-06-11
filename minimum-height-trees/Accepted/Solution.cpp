// https://leetcode.com/problems/minimum-height-trees

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> res;
        vector<int> degree(n,0);
        for (auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);
                degree[i]--;
            }
        }
        while (!q.empty()) {
            int size = q.size();
            res.clear();

            for (int i = 0; i < size; ++i) {
                int front = q.front();
                q.pop();
                res.push_back(front);
                
                for (auto a:adj[front]) {   
                    degree[a]--;
                    if (degree[a] == 1)
                        q.push(a);
                }
            }
        }

        return res;
    }
};