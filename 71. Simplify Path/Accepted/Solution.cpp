// https://leetcode.com/problems/simplify-path/description/

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        if (n == 1 && path[0] == '/')
            return "/";
        string res;
        stack<string> st;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') continue;
            string temp;
            while (i<path.size() && path[i] != '/') {
                temp += path[i];
                ++i;
            }
            if (temp == ".") {
                continue;
            } else if (temp == ".." && !st.empty()) {
                st.pop();
            } else {
                if (temp != "..")
                    st.push(temp);
            }
        }
        while (!st.empty()) {
            res = "/" + st.top() +res;
            st.pop();
        }
        return res == "" ? "/" : res;
    }
};