// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        while (n) {
            
            if (n & 1)
                count++;
            n = n >> 1;
        }
        
        if (count == 1)
            return true;
        return false;
    }
};