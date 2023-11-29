// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class Solution {
public:
    vector<int> parent;
    vector<int> size, rank;
    void disjoint_set(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        rank.resize(n+1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
            rank[i] = 0;
        }
    }
    int find_parent(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find_parent(parent[u]);
    }
    void find_union_by_size(int u, int v) {
        int pu = find_parent(u);
        int pv = find_parent(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    void find_union_by_rank(int u, int v) {
        int pu = find_parent(u);
        int pv = find_parent(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]){
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }   
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra = 0;
        disjoint_set(n);
        for (auto it:connections) {
            int u = it[0];
            int v = it[1];
            if (find_parent(u) == find_parent(v)) extra++;
            else find_union_by_size(u, v);
        }
        int cnt = 0;
        for (int i = 0; i < n;++i) if (parent[i] == i) cnt++;
        return (extra >= (cnt-1)) ? cnt-1:-1;
    }
};
/*


*/