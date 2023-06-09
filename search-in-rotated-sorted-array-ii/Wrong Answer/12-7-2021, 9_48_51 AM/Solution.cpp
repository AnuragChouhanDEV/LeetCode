// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

class Solution {
public:
    bool b_search(vector<int> &nums, int target, int start, int end) {
        int left = nums[start];
        int right = nums[end];
        int mid = (start + end) / 2;
        int middle = nums[mid];
        if (start > end)
            return false;
        if (target == middle)
            return true;
        else if (start <= middle) {
            if (target > nums[start] && target < nums[mid])
                b_search(nums, target, start, mid-1);
            else
                b_search(nums, target, mid+1, end);
        } else {
            if (target > nums[start] && target < nums[end])
                b_search(nums, target, mid+1, end);
            else
                b_search(nums, target, start, mid-1);
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        return b_search(nums, target, 0, nums.size()-1);
    }
};