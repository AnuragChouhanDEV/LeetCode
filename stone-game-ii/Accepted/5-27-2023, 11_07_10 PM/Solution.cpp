// https://leetcode.com/problems/stone-game-ii

class Solution {
public:
    int helper(vector<int>& piles, vector<int> &suff_sum, vector<vector<int>> &dp, int idx, int M) {
        if (idx >= piles.size()) return 0;
        if (idx + 2 * M >= piles.size()) return suff_sum[idx];
        if (dp[idx][M] != 0) return dp[idx][M];
        int result = INT_MIN;
        for (int i = 1; i <= 2 * M; ++i) 
            result = max(result, suff_sum[idx] - helper(piles, suff_sum, dp, idx+i, max(i,M)));
        return dp[idx][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        if (piles.size() == 0) return 0;
        vector<vector<int>> dp(piles.size(), vector<int> (piles.size(), 0));
        vector<int> suff_sum(piles.size());
        suff_sum[suff_sum.size()-1] = piles[piles.size()-1];
        for (int i = suff_sum.size()-2; i >= 0; --i) {
            suff_sum[i] = piles[i]+suff_sum[i+1];
        }
        return helper(piles, suff_sum, dp, 0, 1);
    }
};