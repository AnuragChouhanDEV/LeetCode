// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int _mcs(vector<int>& cost, int n) {
        if (n <= 0) return 0;
        return min(_mcs(cost,n-1) + cost[n], _mcs(cost,n-2) + cost[n-1]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size()-1;
        return _mcs(cost, n);
    }
};