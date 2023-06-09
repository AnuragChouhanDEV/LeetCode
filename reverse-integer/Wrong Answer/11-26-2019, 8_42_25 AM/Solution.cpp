// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x > 0) {
            ret = ret*x + x%10;
            x = x/10;
        }
        return ret;
    }
};