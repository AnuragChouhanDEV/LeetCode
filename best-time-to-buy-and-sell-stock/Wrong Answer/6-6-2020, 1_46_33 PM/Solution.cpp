// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int sum = 0;
        for (int i = 0; i < len - 1; ++i) {
            if (prices[i+1] > prices[i])
                sum = prices[i+1] - prices[i];
        }
        return sum;
    }
};