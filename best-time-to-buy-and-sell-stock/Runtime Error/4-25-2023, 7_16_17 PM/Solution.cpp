// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = INT_MAX;
        int mini_idx = 0;
        for (int i = 0; i < prices[prices.size()-1]; ++i) {
            if (mini > prices[i]) {
                mini = prices[i];
                mini_idx = i;
            }
        }
        for (int i = prices.size()-1; i > mini_idx; --i) {
            profit = max(profit, prices[i]-prices[mini_idx]);
        }
        return profit;
    }
};