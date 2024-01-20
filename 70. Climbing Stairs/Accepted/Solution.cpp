// https://leetcode.com/problems/climbing-stairs/description/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> vec(n,1);
        if (n == 1)
            return 1;
        vec[0] = 1;
        if (n == 2)
            return 2;
        vec[1] = 2;
        for (int i = 2; i < n; ++i) {
            vec[i] = vec[i-1] + vec[i-2];
        }
        return vec[n-1];
    }
};
/*
1111
112
121
211
22

1 2 3 5
11111
1112
1121
1211
2111
212
221
122
*/