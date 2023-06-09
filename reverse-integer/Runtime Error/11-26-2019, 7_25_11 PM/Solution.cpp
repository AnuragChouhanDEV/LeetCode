// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        bool neg = false;
        if (x < 0)
            neg = true;
        x = abs(x);
        while (x > 0) {
            if ((ret*10 + x%10) < 0)
                return 0;
            ret = ret*10 + x%10;
            x = x/10;
        }
        if (neg == true)
            ret = -ret;
        return ret;
    }
};