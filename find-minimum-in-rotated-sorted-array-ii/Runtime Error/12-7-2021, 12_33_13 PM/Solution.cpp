// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int minn = nums[0];
        while (l <= r) {
            //cout << l << " " << r << endl;
            if (nums[l] < nums[r]) {
                minn = min(minn, nums[l]);
                break;
            }
            int mid = (l + r) /2;
            minn = min(minn, nums[l]);
            if (nums[mid] >= nums[l]) {
                while (mid+1 <= nums.size()-1 && nums[mid+1] == nums[mid])
                    mid--;
                l = mid+1;
            } else {
                while (mid-1 >= 0 && nums[mid-1] == nums[mid])
                    mid++;
                r = mid;
            }
        }
        return minn;
    }
};