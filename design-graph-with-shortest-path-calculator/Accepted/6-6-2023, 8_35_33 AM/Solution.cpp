// https://leetcode.com/problems/design-graph-with-shortest-path-calculator

class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for (auto e:edges)
            adj[e[0]].push_back({e[1], e[2]});
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,node1});
        vector<int> cost(adj.size(), INT_MAX);
        cost[node1]=0;

        while(!pq.empty()) {
            int curr_cost = pq.top().first;
            int curr_node = pq.top().second;
            pq.pop();

            for (auto neighbour:adj[curr_node]) {
                if (cost[neighbour.first] > cost[curr_node] + neighbour.second) {
                    cost[neighbour.first] = cost[curr_node] + neighbour.second;
                    pq.push({cost[neighbour.first], neighbour.first});
                }
            }
        }
        return cost[node2] == INT_MAX ? -1: cost[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */