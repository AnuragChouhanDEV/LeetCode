// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        int j = 0;
        for (int i = 1; i < colors.size(); ++i) {
            if (colors[i] == colors[j]) {
                if (neededTime[i] > neededTime[j]) {
                    cost += neededTime[j];
                } else {
                    cost += neededTime[i];
                    continue;
                }
            }
            j=i;
        }
        return cost;
    }
};