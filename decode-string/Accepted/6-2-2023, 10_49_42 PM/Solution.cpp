// https://leetcode.com/problems/decode-string

class Solution {
public:
    string _decode(string &s, int &i) {
        string res;
        while (i < s.size() && s[i] != ']') {
            if (isdigit(s[i])) {
                int k = 0;
                while (i < s.size() && isdigit(s[i])) {
                    k = k*10 + s[i++]-'0';
                }
                i++;
                string str = _decode(s,i);
                while(k-- > 0) {
                    res += str;
                }
                i++;
            } else
                res += s[i++];
        }
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return _decode(s, i);
    }
};