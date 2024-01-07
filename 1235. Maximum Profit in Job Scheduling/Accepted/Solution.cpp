// https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/?envType=daily-question&envId=2024-01-06

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
#if 1
        int numJobs = profit.size(); // Number of jobs
        vector<tuple<int, int, int>> jobs(numJobs);
      
        for (int i = 0; i < numJobs; ++i) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
      
        sort(jobs.begin(), jobs.end());
        vector<int> dp(numJobs + 1);
      
        for (int i = 0; i < numJobs; ++i) {
            auto [endTime, startTime, profit] = jobs[i];
          
            int latestNonConflictJobIndex = upper_bound(jobs.begin(), jobs.begin() + i, startTime, [&](int time, const auto& job) -> bool {
                return time < get<0>(job);
            }) - jobs.begin();
          
            dp[i + 1] = max(dp[i], dp[latestNonConflictJobIndex] + profit);
        }
      
        return dp[numJobs];
#endif

    }
};

/*
1 -> {3,0} {4,-1} {6,-1}
2 -> {5,1} {6,-1}
3 -> {10,2} 
4 -> {6,3} 
6 -> {9,4}


*/