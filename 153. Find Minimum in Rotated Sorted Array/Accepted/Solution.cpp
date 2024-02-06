// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int res = 5001;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] >= nums[left]) {
                res = min(res,nums[left]);
                left = mid+1;
            } else {
                res = min(res,nums[mid]);
                right = mid-1;
            }
        }
        return res;
    }
};