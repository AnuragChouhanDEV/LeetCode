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
        int j = size-1;
        int max1 = 0;
        while (i < size - 1) {
            while ((i < size - 1) && (prices[i + 1] <= prices[i]))
                i++;
            //cout << i << endl;
            if (i == size - 1)
                break;
            buy = i++;
            //cout << buy << endl;
            while ((prices[j] >= prices[j - 1]))
                --j;
            sell = j - 1;
            max1 = max(max1, prices[sell] - prices[buy]);
        }
        //cout <<  sell << " "<< buy << endl;
        return max1;
    }
};