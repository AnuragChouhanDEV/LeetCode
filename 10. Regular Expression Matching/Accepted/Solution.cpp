// https://leetcode.com/problems/regular-expression-matching/description/

class Solution {
public:
#if 1
     bool isMatch(string s, string p) {
        int pn = p.size(), sn = s.size();
        vector<vector<bool>> dp(sn+1, vector<bool>(pn+1, 0));
        dp[sn][pn] = 1;
        for(int i = sn; i >= 0; i--) 
            for(int j = pn - 1; j >= 0; j--) 
                if(p[j+1]=='*') 
					dp[i][j] = dp[i][j+2] || i < sn && (p[j] == '.' || s[i] == p[j]) && dp[i+1][j]; // update of match from * onwards
                else 
                    dp[i][j] = i < sn && (p[j] == '.' || s[i] == p[j]) && dp[i+1][j+1]; // update if char matches or '.'
        return dp[0][0];
    }
#endif
#if 0
    bool dfs(string s, string p, int i, int j, vector<vector<char>> &dp) {
        int pn=p.size(), sn = s.size();
        if(j==pn) return (i == sn); // return true only if done with s
        if (dp[i][j] != -1) return dp[i][j];
        if(p[j+1]=='*') {
            if(dfs(s, p, i, j+2, dp)) return dp[i][j] = true;
            while(i<sn && (p[j]==s[i]||p[j]=='.')) 
				if(dfs(s, p, ++i, j+2, dp)) return dp[i][j] = true;
        } else if (i<sn && (p[j]=='.'|| s[i]==p[j]) && dfs(s, p, i+1, j+1, dp)) 
		    return dp[i][j] = true;
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int sn = s.size();
        int pn = p.size();
        vector<vector<char>> dp(sn+1,vector<char>(pn+1,-1));
        return dfs(s, p, 0, 0, dp);
    }
#endif
};