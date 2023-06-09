// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.length();
        map<char,int> m;
        int first = 0;
        if (len == 0)
            return -1;
        for (int i = 0; i < len;++i) {
            m[s[i]]++;
        }
        for (int i = 0; i < len;++i) {
            if (m[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
};