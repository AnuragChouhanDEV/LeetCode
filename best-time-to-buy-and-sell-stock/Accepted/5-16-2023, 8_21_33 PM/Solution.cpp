// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if (prices.size() == 0)
            return 0;
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (min_price > prices[i])
                min_price = prices[i];
            else
                profit = max(profit, prices[i]-min_price);
        }
        return profit;
    }
};