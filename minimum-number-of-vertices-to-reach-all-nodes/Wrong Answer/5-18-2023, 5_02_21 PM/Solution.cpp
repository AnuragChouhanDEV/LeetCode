// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        unordered_set<int> s1;
        unordered_set<int> s2;

        for (int i = 0; i < edges.size(); ++i) {
            if (s1.find(edges[i][0]) != s2.end() || s2.find(edges[i][0]) != s2.end())
                s2.insert(edges[i][1]);
            else {
                s1.insert(edges[i][0]);
                s2.insert(edges[i][1]);
            }
        }
        vector<int> res(s1.begin(), s1.end());
        return res;
    }
};