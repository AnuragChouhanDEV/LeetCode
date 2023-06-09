// https://leetcode.com/problems/course-schedule

class Solution {
    bool is_cyclic(vector<vector<int>>& adj, vector<int>& visited, int curr) {
        if (visited[curr] == 2)
            return true;
        //cout << visited[curr] << " " << curr<< endl;
        visited[curr] = 2;
        for (int i = 0;i < adj[curr].size();++i) {
            if (visited[adj[curr][i]] != 1) {
                if (is_cyclic(adj, visited, adj[curr][i])) {
                    return true;
                }
            }
        }
        visited[curr] = 1;
        return false;
        
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int len = prerequisites.size();
        if (len == 0)
            return false;
        vector<vector<int>> adj(numCourses);
        for (int i=0;i<len;++i) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> visited(numCourses,0);
        for (int i =0;i < numCourses;++i) {
            if (visited[i] == 0) {
                if (is_cyclic(adj,visited,i)) {
                    return false;
                }
            }
        }
        return true;
    }
};