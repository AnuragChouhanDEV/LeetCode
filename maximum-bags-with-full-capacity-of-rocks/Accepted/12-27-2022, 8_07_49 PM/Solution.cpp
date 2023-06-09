// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        int result = 0;
        for (int i = 0; i < n; ++i)
            capacity[i] -= rocks[i];
        sort(capacity.begin(), capacity.end());
        for (int i = 0; i < n; ++i) {
            if (additionalRocks - capacity[i] >= 0) {
                additionalRocks -= capacity[i];
                result++;
            } else {
                break;
            }
        }
        return result;
    }
};