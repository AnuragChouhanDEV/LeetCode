// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int f,l,mid;
        f = 1;
        l = n;
        long int pos = 1;
        while(f<=l){
            mid = f + (l-f)/2;
            if(isBadVersion(mid)){
                pos = mid;
                l = mid-1;
            }
            else
                f = mid+1;
        }
        return pos;
    }
};