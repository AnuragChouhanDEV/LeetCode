// https://leetcode.com/problems/keys-and-rooms

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n,false);
        queue<int> q;
        q.push(0);
        
        while(!q.empty()) {
            int idx = q.front();
            visited[idx] = true;
            q.pop();

            for (auto a:rooms[idx]) {
                if (!visited[a])
                    q.push(a);
            }
        }
        for (auto a:visited)
            if (a==false)
                return false;
        return true;
    }
};