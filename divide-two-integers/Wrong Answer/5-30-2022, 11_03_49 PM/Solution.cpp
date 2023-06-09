// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 1<<31 && divisor == -1) return INT_MAX;
        bool sign = (dividend >= 0) && (divisor >= 0) ? true : false;
        dividend = abs(dividend);
        divisor = abs(divisor);
        int result = 0;
        while (dividend - divisor >= 0) {
            int count = 0;
            while (dividend - (divisor << 1 << count) >= 0)
                count++;
            result += 1 << count;
            dividend -= divisor << count;
        }
        return sign ? result: -result;
    }
};