// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            int aa = a&(1<<i);
            int bb = b&(1<<i);
            int cc = c&(1<<i);
            if (!aa && !bb && cc) count++;
            else if (!aa && bb && !cc) count++;
            else if (aa && !bb && !cc) count++;
            else if (aa && bb && !cc) count += 2;
        }
        return count;
    }
};