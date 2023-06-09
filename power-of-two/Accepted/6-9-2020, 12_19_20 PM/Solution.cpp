// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        int i = 32;
        if (n & 0x80000000)
            return false;
        while (n && i) {
            if (n & 1)
                count++;
            n = n >> 1;
            --i;
        }
        
        if (count == 1)
            return true;
        return false;
    }
};