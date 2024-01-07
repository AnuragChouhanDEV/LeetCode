// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
#if 1
        int n = nums.size();
    int total_count = 0;

    // Use vector<vector<pair<int, int>>> instead of vector<unordered_map<int, int>>
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>());

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int flag = 0;
            long long diff = (long long)(nums[i]) - nums[j];

            if (diff > INT_MAX || diff < INT_MIN)
                continue;

            int diff_int = (int)(diff);

            // Use push_back to add a new pair to the vector
            dp[i].push_back({diff_int, 1});

            for (const auto& p : dp[j]) {
                if (p.first == diff_int) {
                    dp[i].back().second += p.second;
                    total_count += p.second;
                }
            }
        }
    }

    return total_count;
#endif
#if 0
        int n = nums.size();
        int total_count = 0;

        vector<unordered_map<int, int>> dp(n);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int flag = 0;
                long long diff = (long long)(nums[i]) - nums[j]; 

                if (diff > INT_MAX || diff < INT_MIN)
                    continue; 

                int diff_int = (int)(diff);

                dp[i][diff_int] += 1; 

                if (dp[j].count(diff_int)) {
                    dp[i][diff_int] += dp[j][diff_int];
                    total_count += dp[j][diff_int];
                }
            }
        }

        return total_count;
#endif
    }
};

/*
i=2, j=1
ans = 1+2+1+3 = 7
2 4 6 8 10
ma0 
ma1 2 -> 1
ma2 4 -> 1   2 -> 2
ma3 6 -> 1   4 -> 1   2 -> 3
ma4 8 -> 1   6 -> 1   4 -> 2   2 -> 4

*/