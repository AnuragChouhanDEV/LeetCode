// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int minn = nums[0];
        while (l <= r) {
            if (nums[l] < nums[r]) {
                minn = min(minn, nums[l]);
                break;
            }
            int mid = (l + r) /2;
            minn = min(minn, nums[l]);
            if (nums[mid] >= nums[l])
                l = mid+1;
            else
                r = mid-1;
        }
        return minn;
    }
};