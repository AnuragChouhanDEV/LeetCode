// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 1)
            return 0;
        int buy = 0;
        int sell = 0;
        int i = 0;
        while (i < size - 1) {
            while ((i < size - 1) && (prices[i + 1] <= prices[i]))
                i++;
            if (i == size - 1)
                break;
            buy = i++;
            while ((i < size) && (prices[i] >= prices[i - 1]))
                i++;
            sell = i - 1;
        }
        //cout <<  prices[sell] - prices[buy] << endl;
        return prices[sell] - prices[buy];
    }
};