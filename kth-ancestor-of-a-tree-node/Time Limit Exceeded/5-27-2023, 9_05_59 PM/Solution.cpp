// https://leetcode.com/problems/kth-ancestor-of-a-tree-node

class TreeAncestor {
public:
    int size;
    vector<int> arr;
    TreeAncestor(int n, vector<int>& parent) {
        size = n;
        arr.resize(n);
        for (int i = 0; i < n; ++i) arr[i]=parent[i];
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = k-1; i >= 0; --i) {
            if (arr[node] == -1)
                return -1;
            int tmp = arr[node];
            node = tmp;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */