// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> vec[n];
        for (auto it:flights)
            vec[it[0]].push_back({it[1],it[2]});
        queue<pair<int, pair<int,int>>> q;
        // {stops, {node, cost}}
        q.push({0,{src,0}});
        vector<int> dest(n, 1e9);
        dest[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (stops > k) continue;
            for (auto itr:vec[node]) {
                int adjnode = itr.first;
                int addcost = itr.second;

                if (cost + addcost < dest[adjnode] && stops <= k) {
                    dest[adjnode] = cost + addcost;
                    q.push({stops+1,{adjnode, dest[adjnode]}});
                }
            }
        }
        return dest[dst] == 1e9 ? -1: dest[dst];
    }
};