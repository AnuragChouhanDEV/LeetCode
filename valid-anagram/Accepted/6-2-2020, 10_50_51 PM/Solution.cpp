// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();
        if (l1 != l2)
            return false;
        map<char,int> m;
        for(int i=0;i<l1;++i) {
            m[s[i]]++;
            m[t[i]]--;
        }
        for(int i=0;i<l1;++i) {
            if (m[s[i]] != 0 || m[t[i]] != 0)
                return false;
        }
        return true;
    }
};