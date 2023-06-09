// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> ast;
        vector<int> res;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (ast.empty()) {ast.push(asteroids[i]); continue;}
            if (asteroids[i] < 0) {
                int t = ast.top();
                if (t > 0) {
                    if (abs(t) < abs(asteroids[i])) {
                        while (!ast.empty() && ast.top() > 0 && abs(ast.top()) < abs(asteroids[i]))
                            ast.pop();
                        ast.push(asteroids[i]);
                    } else if (abs(t) == abs(asteroids[i])) {
                        ast.pop();
                    } else {}
                } else {
                    ast.push(asteroids[i]);
                }
            } else {
                ast.push(asteroids[i]);
            }
            while(ast.size() >= 2) {
                int first = ast.top();ast.pop();
                int second = ast.top();ast.pop();
                if ((first < 0 && second < 0) ||(first > 0 && second > 0)) {
                    ast.push(second);
                    ast.push(first);
                    break;
                }
                else if (first > 0 && second < 0) {
                    ast.push(second);
                    ast.push(first);
                    break;
                }
                else {
                    if (abs(first) > abs(second)) {
                        ast.push(first);
                    } else if (abs(first) == abs(second)) {}
                    else {ast.push(second);}
                }
            }    
        }
        while(!ast.empty()) {
            res.push_back(ast.top());
            ast.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};