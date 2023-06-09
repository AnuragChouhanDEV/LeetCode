// https://leetcode.com/problems/regular-expression-matching

class Solution {
public:
    bool isMatch_(string s, string p, int s_idx, int p_idx) {
        if (s_idx == s.size())
            return true;
        //cout << s_idx << " " << p_idx << endl;
        if (s[s_idx] == p[p_idx])
            isMatch_(s, p, s_idx+1, p_idx+1);
        else if (p[p_idx] == '.')
            isMatch_(s, p, s_idx+1, p_idx+1);
        else if (p[p_idx] == '*') {
            //cout << " here" <<endl;
            if (p[p_idx-1] && (p[p_idx-1] == s[s_idx] || p[p_idx-1] == '.')) {
                //cout << p[p_idx-1] << " " << p_idx-1 << " " << s[s_idx] << " " << s_idx << endl;
                p.insert(p_idx, 1, p[p_idx-1]);
                //cout << p << endl;
            }
            isMatch_(s, p, s_idx, p_idx);
        } else
            return false;
        //cout << "got here" << endl;
        return false;
    }
    bool isMatch(string s, string p) {
        if (p.size() > s.size())
            return false;
        return isMatch_(s, p, 0, 0);
    }
};