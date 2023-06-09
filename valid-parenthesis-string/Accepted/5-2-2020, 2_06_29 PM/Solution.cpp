// https://leetcode.com/problems/valid-parenthesis-string

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> o,st;
        int len = s.length();
        
        for (int i = 0; s[i] != '\0'; ++i) {
            //printf("s[i] = %d\n", s[i]);
            if (s[i] == '(')
                o.push(i);
            else if (s[i] == '*')
                st.push(i);
            else {
                if (!o.empty()) {
                    o.pop();
                } else if (!st.empty()) {
                    st.pop();
                } else {
                    //printf("o.top = %d, st.top = %d\n", o.top(), st.top());
                    return false;
                }
            }
        }
        
        while(!o.empty()) {
            if (st.empty())
                return false;
            else if (o.top() < st.top()) {
                o.pop();
                st.pop();
            } else
                return false;
        }
        return true;
        
    }
};