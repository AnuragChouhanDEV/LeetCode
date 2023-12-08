// https://leetcode.com/problems/repeated-substring-pattern/description/?envType=daily-question&envId=2023-12-06

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i = 1, j = 0, n = s.size();
        vector<int> dp(n+1,0);
        while( i < s.size() ){
            if( s[i] == s[j] ) dp[++i]=++j;
            else if( j == 0 ) i++;
            else j = dp[j];
        }
        return dp[n]&&dp[n]%(n-dp[n])==0;
    }
};
/*
abcabcabcabd

0 0 0 0 1 2 3 4 5 6 7 8 0
i = 11
j = 0
n = 12

9 && (9 % (12-9) == 0)

*/