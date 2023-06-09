// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int maxf = 0;
        int l = 0;
        unordered_map<char,int> ma;
        for (int r = 0; r < s.size(); ++r) {
            ma[s[r]]++;
            maxf = max(maxf, ma[s[r]]);
            while (r-l+1 - maxf > k) {
                ma[s[l]]--;
                ++l;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};