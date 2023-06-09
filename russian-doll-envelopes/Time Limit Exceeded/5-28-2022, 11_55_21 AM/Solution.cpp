// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int row = envelopes.size();
        int col = envelopes[0].size();
        int count = 1;
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(row,1);
        //int j = 0;
        for (int i = 1; i < row; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1] && 1+dp[j] > dp[i]) {
                    dp[i] = 1+dp[j];
                } 
                count = max(dp[i], count);
            }
        }
        return count;
    }
};