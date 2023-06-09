// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sliding window
        int left = 0;
        int right = 0;
        int min_size = INT_MAX;
        int sum = 0;
        while (left < nums.size()-1) {
            if (sum < target && right < nums.size()) {
                sum+=nums[right];
                right++;
                // 9,6
            } else if (sum >= target) {
                sum-=nums[left];
                min_size = min(min_size, right-left); 
                left++;
                // 3,2,5
            } else {
                if (right-left == nums.size())
                    return 0;
                left++;
                // 6
            }
        }
        return min_size;
    }
};