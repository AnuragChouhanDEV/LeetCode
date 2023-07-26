// https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> v[n];
        /* stops, src, price*/
        for (auto it:flights) {
            v[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int,int>>> q;
        q.push({0,{src, 0}});
        vector<int> dist(n, 1e7);
        dist[src]=0;
        while(!q.empty()) {
            auto itr = q.front();
            int stop = itr.first;
            int src = itr.second.first;
            int price = itr.second.second;
            q.pop();
            if (stop > k)
                continue;
            for (auto it:v[src]) {
                int dest = it.first;
                int e_cost = it.second;
                if (price + e_cost < dist[dest] && stop <= k) {
                    dist[dest] = price + e_cost;
                    q.push({stop+1, {dest, price + e_cost}});
                }
            }

        }
        if (dist[dst] == 1e7) return -1;
        return dist[dst];
    }
};