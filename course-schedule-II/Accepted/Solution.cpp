// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> adj(numCourses);
        vector<int> in_degree(numCourses, 0);
        for (int i = prerequisites.size()-1; i >= 0; --i) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
            in_degree[a]++;
        }
        queue<int> q;
        for (int i = 0 ; i < numCourses; ++i) {
            if (in_degree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto a:adj[node]) {
                in_degree[a]--;
                if (in_degree[a] == 0)
                    q.push(a);
            }
        }
        return res.size() == numCourses ? res: vector<int> {};
    }
};