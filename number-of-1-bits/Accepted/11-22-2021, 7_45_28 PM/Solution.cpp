// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int set_bits = 0;
        while (n) {
            set_bits += n&1;
            n = n >> 1;
        }
        return set_bits;
    }
};