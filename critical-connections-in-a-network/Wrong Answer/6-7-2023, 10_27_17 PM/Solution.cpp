// https://leetcode.com/problems/critical-connections-in-a-network

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> res;
        vector<vector<int>> adj_mat(n,vector<int>(n,0));
        for (int i = 0; i < connections.size();++i) {
            adj_mat[connections[i][0]][connections[i][1]]=1;
            adj_mat[connections[i][1]][connections[i][0]]=1;
        }
        for (int i = 0; i < n; ++i) {
            int count = 0;
            vector<int> r(2,0);
            bool flag = false;
            for (int j = 0; j < n; ++j) {
                if (adj_mat[i][j]) {
                    r[0] = i;
                    r[1] = j;
                    count++;
                }
            }
            if (count == 1) {
                if (res.size()) {
                    for (int i = 0; i < res.size(); ++i) {
                        reverse(r.begin(), r.end());
                        if (res[i] == r) flag = true;
                        reverse(r.begin(), r.end());
                    }
                }
                if (!flag)
                    res.push_back(r);
            }
        }
        return res;

    }
};