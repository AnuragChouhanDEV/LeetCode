// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        int idx = 0;
        while(--n) {
            string ts;
            int i = 0;
            while(i<s.size()) {
                int count = 1;
                while(i+1 < s.size() && s[i] == s[i+1]) {
                    ++i;
                    ++count;
                }
                ts += to_string(count) +s[i];
                ++i;
            }
            s=ts;
        }
        
        return s;
    }
};