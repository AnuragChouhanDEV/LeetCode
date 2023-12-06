// https://leetcode.com/problems/calculate-money-in-leetcode-bank/?envType=daily-question&envId=2023-12-06

class Solution {
public:
    int totalMoney(int n) {
#if 1
        if (n <= 7) return (n * (n+1))/2;
        int k = n/7;
        int l = n%7;
        int res = 0;
        int i = 0;
        for (; i < k;++i) {
            res += (((i+7) * ((i+7)+1))/2) - ((i * (i+1))/2);
        }
        //cout << res << " ";
        res += (((i+l) * ((i+l)+1))/2) - ((i * (i+1))/2);

        return res;
#endif
    }
};
/*
7*8/2
3
4*5/2= 10 -
1*2/2= 1

*/