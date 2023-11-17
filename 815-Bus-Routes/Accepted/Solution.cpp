// https://leetcode.com/problems/bus-routes/description/?envType=daily-question&envId=2023-11-12

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> route_to_bus;
        for (int bid = 0; bid < routes.size(); ++bid) {
            vector<int> route = routes[bid];
            for (auto it:route) {
                route_to_bus[it].push_back(bid);
            }
        }

        queue<pair<int,int>> q;
        unordered_map<int, bool> bvis, rvis;
        q.push({source,0});
        rvis[source] = true;

        while (!q.empty()) { 
            int size = q.size();
            while (size--) {
                pair<int, int> p = q.front();
                q.pop();

                int stop = p.first;
                int bus_count = p.second;

                if (stop == target) return bus_count;

                for (auto bus:route_to_bus[stop]) {
                    if (bvis[bus]) continue;
                    bvis[bus] = true;
                    for (auto bstop:routes[bus]) {
                        if (rvis[bstop]) continue;
                        rvis[bstop] = true;
                        q.push({bstop ,bus_count+1});
                    }
                }
            }
        }

        return -1;

    }
};

/*
map
2 -> 0 -> 1
8 -> 1

map bus
map stop
q 

*/