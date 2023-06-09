// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i; 
        int len = s.length(); 
        int st = 0; 
        int currlen; 
        int maxlen = 0; 
        int start; 
        unordered_map<char, int> pos; 
        pos[s[0]] = 0; 
  
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
    if (maxlen < i - st) { 
        maxlen = i - st; 
        start = st; 
    } 
  
    //return s.substr(start, maxlen); 
        return maxlen;
    }
};