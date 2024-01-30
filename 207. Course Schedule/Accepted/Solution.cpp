// https://leetcode.com/problems/course-schedule/description/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for (auto p: prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int visited = 0;
        while(!q.empty()) {
            int node = q.front();
            visited++;
            q.pop();
            for (auto it:adj[node]) {
                indegree[it]--;
                if (indegree[it]==0)
                    q.push(it);
            }
        }
        return visited == numCourses;
    }
};