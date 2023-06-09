// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int mid;
        int result = n;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                result = mid;
                left = mid - 1;
            }
            else
                right = mid + 1;
        }
        return result;
        
    }
};