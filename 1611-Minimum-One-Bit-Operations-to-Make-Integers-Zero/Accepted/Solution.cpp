// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/?envType=daily-question&envId=2023-11-30

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n==0) return 0;
        // take log2 to get msb
        int k=floor(log2(n));
        // get msb number
        int numOp=(1<<(k+1))-1;
        // remove the ops of lsb from msb       
        return numOp-minimumOneBitOperations(n^(1<<k));
    }
};
/*
1000
11000
1000
0111
0110
0010
0011
0001

*/