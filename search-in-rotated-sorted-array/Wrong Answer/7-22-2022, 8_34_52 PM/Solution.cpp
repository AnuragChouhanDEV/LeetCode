// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int helper(vector<int>& nums, int left, int right, int target) {
        if (right < left)
            return -1;
        int mid = (left + right)/2;
        if (nums[mid] == target)
            return mid;
        if (target < nums[mid]) {
            if (target < nums[left])
                return helper(nums, mid+1, right, target);
            return helper(nums, left, mid-1, target);
        } else {
            return helper(nums, mid+1, right, target);
        }
    }
    int search(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size()-1, target);
#if 0
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == target)
                return i;
        return -1;
#endif
    }
};