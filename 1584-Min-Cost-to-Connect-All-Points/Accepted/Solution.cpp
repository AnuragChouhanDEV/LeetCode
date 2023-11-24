// https://leetcode.com/problems/min-cost-to-connect-all-points/description/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int>> adj[n];
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int x1 = points[i][0]; int y1 = points[i][1];
                int x2 = points[j][0]; int y2 = points[j][1];

                int dist = abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,dist}); adj[j].push_back({i,dist});
            }
        }
        vector<bool> vis(n, false);
        int sum = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});

        while (!pq.empty()) {
            pair<int,int> p = pq.top();
            pq.pop();

            int wt = p.first;
            int node = p.second;

            if(vis[node]) continue;
            vis[node] = true;
            sum += wt;

            for (auto it:adj[node]) {
                int adjnode = it.first;
                int adjwt = it.second;
                if (!vis[adjnode])
                    pq.push({adjwt, adjnode});
            }
        }
        return sum;
    }
};