// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool dfs(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &stack) {
        stack[src] = 1;
        visited[src] = true;
        for (auto i:adj[src]) {
            if (!visited[i]) {
                if (dfs(i,adj,visited,stack))
                    return true;
            }
            if(visited[i] && stack[i])
                return true;
       }
        stack[src] = 0;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto a:prerequisites) {
            adj[a[0]].push_back(a[1]);
        }
        vector<int> stack(numCourses, 0);
        vector<bool> visited(numCourses, 0);
        bool cycle = true;
        for (int i = 0; i < numCourses;++i) {
            if (!visited[i])
                if (dfs(i,adj,visited,stack))
                    cycle = false;
        }
        return cycle;
    }
};