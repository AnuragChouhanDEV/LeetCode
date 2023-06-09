// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return (double)nums[0];
        int left = 0;
        int right = 0;
        int sum = 0;
        int maxi = 0;
        while (right < k) {
            sum += nums[right];
            ++right;
        }
        if (n == k) return (double)sum/(double)k;
        while (right < n) {
            sum = sum-nums[left]+nums[right];
            maxi = max(maxi, sum);
            cout << sum << endl;
            left++;right++;
        }
        return (double)maxi/(double)k;
    }
};