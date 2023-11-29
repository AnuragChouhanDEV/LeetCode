// https://leetcode.com/problems/number-of-1-bits/description/?envType=daily-question&envId=2023-11-29

class Solution {
public:
    int hammingWeight(uint32_t n) {
        if (n == 0) return 0;
        /*
        int count = 0;
        while (n) {
            count++;
            n &= (n-1);
        }
        return count;
        */    
        return 1 + hammingWeight(n & n-1);
    
    }
};