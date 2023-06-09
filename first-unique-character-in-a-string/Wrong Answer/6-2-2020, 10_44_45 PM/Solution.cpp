// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.length();
        map<char,int> m;
        int first = 0;
        for (int i = 0; i < len;++i) {
            m[s[i]]++;
        }
        for (int i = 0; i < len;++i) {
            if (m[s[i]] == 1)
                return i;
        }
        
        return 0;
    }
};