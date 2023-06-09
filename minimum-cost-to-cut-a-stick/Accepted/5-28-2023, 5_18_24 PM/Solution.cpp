// https://leetcode.com/problems/minimum-cost-to-cut-a-stick

class Solution {
public:
    int helper(int i, int n, vector<int>& cuts, int left, int right, vector<vector<int>> &dp) {
        if (left > right) return 0;
        if (dp[left][right] != -1) return dp[left][right];
        int cost = INT_MAX;
        for (int j = left; j <= right; ++j) {
            int left_cost = helper(i, cuts[j], cuts, left, j-1, dp);
            int right_cost = helper(cuts[j], n, cuts, j+1, right, dp);
            int curr_cost = (n - i)+left_cost+right_cost;
            cost = min(cost, curr_cost);
        }
        return dp[left][right] = cost;
        
    }
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(101, vector<int>(101, -1));
        sort(cuts.begin(), cuts.end());
        return helper(0, n, cuts, 0, cuts.size()-1, dp);
    }
};