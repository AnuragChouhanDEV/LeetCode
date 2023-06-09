// https://leetcode.com/problems/find-the-highest-altitude

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int sum = 0;
        for (int i = 0; i < gain.size(); ++i) {
            sum += gain[i];
            res = max(res, sum);
        }
        return res;
    }
};
/*
-5 1  5 0 -7
0 -5 -4 1 1 -6

-4 -3 -2 -1  4    3 2
0  -4 -7 -9  -10 -6 -3
*/