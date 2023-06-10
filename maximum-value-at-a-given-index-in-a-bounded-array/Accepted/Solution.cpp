// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int left = index;
        int right = n-index-1;

        int lo = 1;
        int hi = maxSum;

        int res = 0;
        while (lo <= hi) {
            long long mid = (long long)(lo + (hi-lo)/2);
            long long left_sum = 0;
            long long right_sum = 0;
            long long m = mid-1;
            long long sum = mid;

            if (right <= m) {
                right_sum = m*(m+1)/2 - ((m-right)*(m-right+1)/2);
            } else {
                right_sum = m*(m+1)/2 + 1*(right-m);
            }
            if (left <= m) {
                left_sum = m*(m+1)/2 - ((m-left)*(m-left+1)/2);
            } else {
                left_sum = m*(m+1)/2 + 1*(left-m);
            }
            sum+=right_sum+left_sum;
            if (sum <= (long long)maxSum) {
                res = mid;
                lo = mid+1;
            } else
                hi = mid-1;
        }
        return res;
    }
};