// https://leetcode.com/problems/count-number-of-homogenous-substrings/description/

class Solution {
public:
    int countHomogenous(string s) {
        int MOD = 1000000007;
        int res = s.size();
        int cnt = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1]) {
                res = (res+cnt)%MOD;
                cnt++;
            } 
            else
                cnt = 1;
        }
        return res;
    }
};