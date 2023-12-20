// https://leetcode.com/problems/buy-two-chocolates/description/?envType=daily-question&envId=2023-12-20

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int res = money;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] <= firstMin) {
                secondMin = firstMin;
                firstMin = prices[i];
            } else if (prices[i] < secondMin && prices[i] != firstMin) {
                secondMin = prices[i];
            }
        }
        int x = money - firstMin;
        if (x >= secondMin) 
            res = x - secondMin;
        return res;
    }
};
/*
[69,91,78,19,40,13]
94

13 19 40 69 78 91
81 62 
   75 35
      54 
*/