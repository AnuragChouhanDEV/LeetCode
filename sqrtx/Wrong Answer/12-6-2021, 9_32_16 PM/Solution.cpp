// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = x;
        while (start < end) {
            int mid = (start+end)/2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid < x) {
                start = mid + 1;
            } else if (mid * mid > x) {
                end = mid - 1;
            }
        }
        return 0;
    }
};