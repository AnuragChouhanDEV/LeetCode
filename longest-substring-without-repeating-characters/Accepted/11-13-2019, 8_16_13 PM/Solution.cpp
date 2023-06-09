// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i ,len = s.length(); 
        int currlen, start, st = 0, maxlen = 0;  
        unordered_map<char, int> pos;

        if (s[0] && len)
            pos[s[0]] = 0; 
  
        //cout << len << "\n";
        for (i = 1; i < len; i++) { 
            if (pos.find(s[i]) == pos.end()) 
                pos[s[i]] = i; 
            else { 
                if (pos[s[i]] >= st) { 
                    currlen = i - st; 
                    if (maxlen < currlen) { 
                        maxlen = currlen; 
                        start = st; 
                    } 
                    st = pos[s[i]] + 1; 
                } 
            pos[s[i]] = i; 
            }
        } 
        if ((maxlen < i - st) && len > 0) { 
            maxlen = i - st; 
            start = st; 
        } 
        return maxlen;
    }
};