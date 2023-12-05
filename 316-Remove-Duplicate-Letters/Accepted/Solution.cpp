// https://leetcode.com/problems/remove-duplicate-letters/description/?envType=daily-question&envId=2023-12-05

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> v(26,0);
        vector<bool> vis(26,false);
        for (int i = 0; i < s.size();++i) {
            v[s[i]-'a']=i;
        }
        string res = "";
        for (int i = 0 ; i < s.size();++i) {
            if (vis[s[i]-'a']) continue;
            while (!res.empty() && res.back() > s[i] && v[res.back()-'a'] > i) {
                vis[res.back()-'a']=false;
                res.pop_back();
            }
            res += s[i];
            vis[s[i]-'a'] = true;
        }
        return res;
    }
};

/*
"cbacdcbc"
acdb

a 1
b 2
c 4
d 1

*/