// https://leetcode.com/problems/path-crossing/description/

class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0;
        int y = 0;
        unordered_set<string> s;
        for (auto c:path) {
            if (s.find(to_string(x)+"+"+to_string(y)) != s.end()) {
                return true;
            }
            s.insert(to_string(x)+"+"+to_string(y));
            if (c == 'N') y++;
            else if (c == 'E') x++;
            else if (c == 'S') y--;
            else if (c == 'W') x--;
        }
        if (s.find(to_string(x)+"+"+to_string(y)) != s.end()) {
            return true;
        }
        return false;
    }
};