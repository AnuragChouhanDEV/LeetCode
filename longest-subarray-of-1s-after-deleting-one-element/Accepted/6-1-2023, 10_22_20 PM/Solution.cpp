// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int maxi = 0;
        int count = 0;
        int k = 1;
        while (right < n) {
            if (nums[right]==0) count++;
            while (count > k) {
                if (nums[left] == 0) count--;
                left++;
            }
            maxi = max(maxi, right-left);
            right++;
        }
        return maxi;
    }
};