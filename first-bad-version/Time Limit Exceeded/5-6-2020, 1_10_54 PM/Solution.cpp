// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        while (1) {
            if(!isBadVersion(n))
                break;
            n = n/2;
        }
        while (!isBadVersion(n)) {
            ++n;
        }
        return n;
    }
};