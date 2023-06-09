// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        double res = 0;
        bool neg = false;
        if (len == 0)
            return 0;
        int idx = 0;
        while (str[idx] == ' ') {
                idx++;
            }
        if (str[idx] == '-')
            neg = true;
        if (str[idx] == '-' || str[idx] == '+')
            idx++;
        while(idx < len) {
            if (str[idx] < 0 && str[idx] > 9)
                break;
            int val = (int)(str[idx] - '0');
            res = res * 10 + val;
            ++idx;
        }
        if (neg)
            res = -res;
        if (res > INT_MAX)
            return INT_MAX;
        if (res < INT_MIN)
            return INT_MIN;
        return (int)res;
    }
};