// https://leetcode.com/problems/hamming-distance

class Solution {
public:
    int hammingDistance(int x, int y) {
        x = x ^ y;
        int setBits = 0;
        while (x > 0) {
            setBits += x & 1;
            x >>= 1;
        }
        return setBits;
    }
};