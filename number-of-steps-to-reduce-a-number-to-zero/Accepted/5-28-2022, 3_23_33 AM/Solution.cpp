// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero

class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        while(num) {
            num = (num & 1) ? num - 1: num >> 1;
            steps++;
        }
        return steps;
    }
};