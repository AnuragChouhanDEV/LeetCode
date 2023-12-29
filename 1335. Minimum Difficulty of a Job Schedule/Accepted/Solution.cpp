// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/?envType=daily-question&envId=2023-12-29

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        return minDifficultyVersion(jobDifficulty, d);
    }

    int minDifficultyVersion(const vector<int>& jobDifficulty, int d) {
        const int n = static_cast<int>(jobDifficulty.size());

        if (n < d) {
            return -1;
        } else if (n == d) {
            int totalDifficulty = 0;
            for (int difficulty : jobDifficulty)
                totalDifficulty += difficulty;
            return totalDifficulty;
        }

        // dp[j]:
        //    the minimum difficulty OF
        //       the first (j+1) jobs, exactly scheduled in (i+1) days.
        vector<int> dp(n);
        dp[0] = jobDifficulty[0];

        // Initializing the dp array to store the maximum difficulty encountered so far.
        for (int i = 1; i < n; ++i) {
            dp[i] = max(jobDifficulty[i], dp[i - 1]);
        }

        vector<int> dpPrev(n);

        // Dynamic Programming to find the minimum difficulty.
        for (int i = 1; i < d; ++i) {
            dp.swap(dpPrev);
            for (int j = i; j < n; ++j) {
                int lastDayDifficulty = jobDifficulty[j];
                int tmpMin = lastDayDifficulty + dpPrev[j - 1];

                // Iterate to find the minimum difficulty for the current day.
                for (int t = j - 1; i - 1 < t; --t) {
                    lastDayDifficulty = max(lastDayDifficulty, jobDifficulty[t]);
                    tmpMin = min(tmpMin, lastDayDifficulty + dpPrev[t - 1]);
                }

                dp[j] = tmpMin;
            }
        }

        return dp.back();
    }
#if 0
    void helper(vector<int>& jd, int daysLeft, int idx, vector<vector<int>>& memo) {
        int len = jd.size();
        if (memo[daysLeft][idx] != 0) {
            return;
        }
        if (daysLeft == 1) {
            int num = 0;
            for (int i = idx; i < len; i++) {
                num = max(num, jd[i]);
            }
            memo[daysLeft][idx] = num;
            return;
        }
        int maxDifficulty = jd[idx];
        daysLeft--;
        int stop = len - idx - daysLeft + 1;

        int res = INT_MAX;
        for (int i = 1; i < stop; i++) {
            maxDifficulty = max(maxDifficulty, jd[idx + i - 1]);
            int rest = memo[daysLeft][idx + i];
            if (rest == 0) {
                helper(jd, daysLeft, idx + i, memo);
                rest = memo[daysLeft][idx + i];
            }
            res = min(res, rest + maxDifficulty);   
        }
        memo[daysLeft + 1][idx] = res;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int len = jobDifficulty.size();
        if (len < d) {
            return -1;
        }
        int sum = accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);
        if (sum == 0) {
            return 0;
        }
        vector<vector<int>> dp(d + 1, vector<int>(len, 0));
        helper(jobDifficulty, d, 0, dp);
        
        return dp[d][0];
    }
#endif
};