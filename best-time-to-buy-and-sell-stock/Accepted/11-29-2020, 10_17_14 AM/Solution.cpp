// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int maxi = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (min > prices[i])
                min = prices[i];
            else
                maxi = max(maxi, prices[i] - min);
        }
        return maxi;
    }
};