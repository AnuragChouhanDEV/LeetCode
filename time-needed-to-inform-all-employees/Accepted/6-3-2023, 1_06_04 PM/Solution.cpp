// https://leetcode.com/problems/time-needed-to-inform-all-employees

class Solution {
public:
    int total_time = 0;
    int man_time = 0;
    unordered_map<int, vector<int>> m;
    void dfs(int headID, vector<int>& informTime) {
        total_time = max(total_time, man_time);
        for (auto mario:m[headID]) {
            man_time += informTime[headID];
            dfs(mario, informTime);
            man_time -= informTime[headID];
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int i = 0; i < n; ++i) {
            int mario = manager[i]; 
            if (mario != -1) m[mario].push_back(i);
        }
        dfs(headID, informTime);
        return total_time;
    }
};