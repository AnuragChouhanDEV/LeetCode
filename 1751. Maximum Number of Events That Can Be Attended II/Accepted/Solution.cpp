// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/?envType=daily-question&envId=2023-12-06

class Solution {
public:
    int helper(vector<vector<int>>& events, int n, int pos, int k, vector<vector<int>> &dp) {
        if (pos >= n || k == 0) {
            return 0;
        }
        if (dp[k][pos] != -1)
            return dp[k][pos];
#if 0 // linear search
        int i;
        for (i = pos+1;i < n; ++i) {
            if (events[pos][1] < events[i][0]) {
                break;
            }
        }
#else // binary search
        vector<int> temp = {events[pos][1], INT_MAX, INT_MAX};
        int i = upper_bound(events.begin()+pos+1, events.end(), temp)-events.begin();
#endif
        return dp[k][pos] = max(helper(events, n, pos+1, k, dp), events[pos][2] + helper(events, n, i, k-1, dp));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        
        return helper(events, n, 0, k, dp);
    }
};

/*
1 -> 2
2 -> 3
3 -> 4

1 -> 1
2 -> 2
3 -> 3
4 -> 4

*/