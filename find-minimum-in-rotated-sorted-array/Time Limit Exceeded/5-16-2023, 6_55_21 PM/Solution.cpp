// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        if (nums.size() == 1)
            return nums[0];
        while (left < right) {
            mid = left +(right - left)/2;
            //cout << " mid " << mid << " left " << left << " right " << right << endl;
            
            if (nums[mid] > nums[mid+1])
                return nums[mid+1];
            else if (left == mid || right == mid)
                return nums[mid];
            else if (nums[mid] > nums[right]) {
                left = mid+1;
            } else if (nums[mid] > nums[left]) {
                right = mid-1;
            }
        }
        return nums[left];
    }
};