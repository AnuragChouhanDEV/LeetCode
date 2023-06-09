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
            //cout << mid << endl;
            if (isBadVersion(mid)) {
                
                result = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return result;
        
    }
};