// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        long int ret = 0;
        long int ret_p = 0;
        bool neg = false;
        if (x < 0)
            neg = true;
        x = abs(x);
        while (x > 0) {
            if (((ret*10) - ret_p) < 0) {
                printf("here\n");
                return 0;
            }
            ret = ret*10 + x%10;
            x = x/10;
            ret_p = ret;
            printf("%d ", ret);
        }
        if (neg == true)
            ret = -ret;
        return ret;
    }
};