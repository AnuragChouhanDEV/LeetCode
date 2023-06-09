// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    unordered_map<int, unordered_set<int>> ma;

        for (int i = 0; i < edges.size(); ++i) {
            ma[edges[i][0]].insert(edges[i][1]);
            if (ma.find(edges[i][1]) != ma.end())
                ma.erase(edges[i][1]);
            for (auto it = ma.begin();it != ma.end(); ++it) {
                if (it->second.find(edges[i][0]) != it->second.end())
                    ma.erase(edges[i][0]);
            }
        }
        vector<int> res;
        
        for (auto it = ma.begin();it != ma.end(); ++it)
            res.push_back(it->first);
        return res;
    }
};