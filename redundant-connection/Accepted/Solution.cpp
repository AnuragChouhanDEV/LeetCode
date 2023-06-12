// https://leetcode.com/problems/redundant-connection

class Solution {
public:
    int parentof(int n, vector<int> &parent) {
        if (parent[n] == n)
            return n;
        return parentof(parent[n], parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(1001, 0);
        vector<int> res(2,0);
        for (int i = 0; i < parent.size(); ++i)
            parent[i]=i;
        for (auto edge:edges) {
            int n1 = edge[0];
            int n2 = edge[1];
            int p1 = parentof(n1, parent);
            int p2 = parentof(n2, parent);
            if (p1 == p2)
                res = edge;
            parent[p1]=p2;
        }
        return res;
    }
};