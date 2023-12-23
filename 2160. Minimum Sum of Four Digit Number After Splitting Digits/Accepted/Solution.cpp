// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/description/

class Solution {
public:
    int minimumSum(int num) {
        vector<int> vec(10,0);
        for (int i = 0; i < 4; ++i) {
            vec[num%10]++;
            num/=10;
        }
        int num1 = 0;
        int num2 = 0;
        int flag = 0;
        for (int it = 0; it < 10; ++it) {
            if (vec[it]) {
                if (flag) {
                    num1 += it;
                    num1 *=10;
                    flag = 0;
                } else {
                    num2 += it;
                    num2 *=10;
                    flag = 1;
                }
                vec[it]--;
                if (vec[it]) it--;
            }
        }
        return (num1 +num2)/10;
    }
};
/*
1569
16 + 59 = 75
19 + 56 = 75

*/