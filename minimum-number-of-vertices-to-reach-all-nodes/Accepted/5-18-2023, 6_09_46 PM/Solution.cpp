// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res(n, -1);
         vector<int> result;
        for(auto e:edges) res[e[1]]++;
        for (int i = 0; i < n; ++i) if (res[i] == -1) result.push_back(i);
        return result;
    }
};