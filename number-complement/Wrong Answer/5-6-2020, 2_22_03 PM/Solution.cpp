// https://leetcode.com/problems/number-complement

class Solution {
public:
    int findComplement(int num) {
        int result = 0;
        int i = 0;
        
        while (num) {
            if ((num&1) == 0)
                result = result + 1<<i;
            ++i;
            num = num >> 1;
        }
        return result;
    }
};