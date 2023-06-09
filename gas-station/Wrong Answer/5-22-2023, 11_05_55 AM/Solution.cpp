// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = -1;
        int n = gas.size();
        int total_fuel = 0;
        int total_cost = 0;
        int curr_fuel = 0;
        for (int i = 0; i < n; ++i) {
            curr_fuel += gas[i] - cost[i];
            if (curr_fuel < 0) {start = i+1; curr_fuel=0;}
            total_fuel += gas[i];
            total_cost += cost[i];
        }
        if (total_fuel < total_cost) return -1;
        return start;
    }
};


/*

1  2   3   4 5
3  4   5   1 2
--------------
-2 -2 -1   3 3


gas += gas[i]



*/