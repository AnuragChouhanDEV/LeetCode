// https://leetcode.com/problems/possible-bipartition

class Solution {
    bool is_bipartite(vector<vector<int>>& adj, int N, int node, vector<int>& color) {
        queue<int> q;
        q.push(node);
        color[node] = 1;
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int el:adj[curr]) {
                if (color[el] == color[curr]) {
                    return false;
                }
                if (color[el] == -1) {
                    color[el] = 1 - color[curr];
                    q.push(el);
                }
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int len = dislikes.size();
        vector<vector<int>> adj(N+1);
        for (int i = 0; i < len; ++i) {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(N+1, -1);
        for (int i=0;i<N;++i){
            if (color[i] == -1) {
                if (!is_bipartite(adj,N,i,color)) {
                    return false;
                }
            }
        }
        return true;
    }
};