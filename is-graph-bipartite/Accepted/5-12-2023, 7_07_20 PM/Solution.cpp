// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    // 0 -no colot
    // 1 - red
    // -1 - black
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++)
            if (colors[i] == 0) {
                queue<int> q;
                q.push(i);
                colors[i] = 1;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (int adjacent : graph[node])
                        if (colors[adjacent] == colors[node])
                            return false;
                        else if (colors[adjacent] == 0) {
                            q.push(adjacent);
                            colors[adjacent] = -colors[node];
                        }
                }
            }
        return true;
    }
};