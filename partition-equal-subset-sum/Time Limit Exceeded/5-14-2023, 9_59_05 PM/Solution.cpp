// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool isSubsetSum(vector<int> &nums, int n, int sum)
    {
        bool subset[n + 1][sum + 1];
        for (int i = 0; i <= n; i++)
            subset[i][0] = true;
        for (int i = 1; i <= sum; i++)
            subset[0][i] = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j < nums[i - 1])
                    subset[i][j] = subset[i - 1][j];
                if (j >= nums[i - 1])
                    subset[i][j]
                        = subset[i - 1][j]
                        || subset[i - 1][j - nums[i - 1]];
            }
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= sum; ++j) {
                cout << subset[i][j] << " ";
            }
            cout << endl;
        }
        return subset[n][sum];
    }
 
    bool canPartition(vector<int>& nums) {
        int ans = 0;
        for (auto n: nums)
            ans += n;
        if (ans % 2 == 1)
            return false;
        ans = ans/2;
        return isSubsetSum(nums, nums.size(), ans);
    }
};