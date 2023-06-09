// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        long int ret = 0;
        bool neg = false;
        if (x < 0)
            neg = true;
        x = abs(x);
        while (x > 0) {
            ret = ret*10 + x%10;
            if ((ret) > 0x7FFFFFFF) {
                //printf("here\n");
                return 0;
            }
            x = x/10;
            //printf("%d ", ret);
        }
        if (neg == true)
            ret = -ret;
        return ret;
    }
};