// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
    int max_(int a, int b) {
        return a > b ? a : b;
    }
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int max = 0;
        int min = INT_MAX;
        for (int i = 0; i < len; ++i) {
            if (min > prices[i])
                min = prices[i];
            else
                max = max_(max, prices[i] - min);
            //cout << min << " " << max << endl;
        }
        return max;
    }
};