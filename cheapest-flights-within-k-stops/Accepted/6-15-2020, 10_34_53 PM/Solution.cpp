// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
    void visit(vector<vector<int>>& adj, vector<vector<int>>& cost, int src, int dst, int K, int& fare, int tot_cost, vector<bool>& visited) {
        if (K < -1)
            return;
        if (src == dst)
            fare = min(fare, tot_cost);
        visited[src] = true;
        for (int i = 0; i < adj[src].size(); ++i) {
            if (!visited[adj[src][i]] && (tot_cost + cost[src][adj[src][i]] <= fare)) 
                visit(adj, cost, adj[src][i], dst, K-1, fare, tot_cost+cost[src][adj[src][i]], visited);
        }
        visited[src] = false;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> adj(n);
        vector<vector<int>> cost(n+1, vector<int>(n+1));
        
        for (int i = 0; i < flights.size();++i) {
            adj[flights[i][0]].push_back(flights[i][1]);
            cost[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        
        vector<bool> visited(n+1, false);
        int fare = INT_MAX;
        visit(adj, cost, src, dst, K, fare, 0, visited);
        if (fare == INT_MAX)
            return -1;
        return fare;
    }
};