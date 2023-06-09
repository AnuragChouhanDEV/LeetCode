// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        for (int i = s.size()-1; i >= 0; --i) m[s[i]]++;
        for (int i = 0; i < s.size(); ++i) {
            if (m.find(s[i]) != m.end()) {
                if (m[s[i]] == 1)
                    return i;
            }
        }
        return -1;
    }
};