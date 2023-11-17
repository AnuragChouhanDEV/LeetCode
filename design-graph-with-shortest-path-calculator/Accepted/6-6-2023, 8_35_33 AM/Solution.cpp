// https://leetcode.com/problems/design-graph-with-shortest-path-calculator
// https://leetcode.com/problems/design-graph-with-shortest-path-calculator/description/?envType=daily-question&envId=2023-11-11

#if 0

class Graph {
public:
    // source node {dest node, weight}
    unordered_map<int, vector<pair<int,int>>> e;
    int _n;
    Graph(int n, vector<vector<int>>& edges) {
        _n = n;
        for (int i = 0; i < edges.size(); ++i) {
            e[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        e[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        // node, weight
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> wt(_n, INT_MAX);
        wt[node1] = 0;
        pq.push({0, node1});

        while(!pq.empty()) {
            pair<int,int> p = pq.top();
            pq.pop();

            int node = p.second;
            int weight = p.first;

            if(weight > wt[node]) continue;
            if (node == node2) return weight;

            for (auto it:e[node]) {
                if (wt[it.first] > it.second+weight) {
                    int new_wt = it.second+weight;
                    wt[it.first] = new_wt;
                    pq.push({new_wt, it.first});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

 /*

 0 -> (2,5) -> (1,2)
 1 -> (2,1)
 3 -> (0,3)
 
 */

 #endif

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
