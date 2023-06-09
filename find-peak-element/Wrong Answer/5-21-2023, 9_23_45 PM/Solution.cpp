// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = nums.size()-1;
        //int n = nums.size();
        if (n == 1)
            return 0;
        if (n == 2)
            return nums[0] > nums[1] ? nums[0] : nums[1];
        while(left <= right) {
            int mid = left + (right-left)/2;
            if (mid - 1 >= 0 && nums[mid] > nums[mid-1] && mid + 1 >= n)
                return mid;
            else if (mid - 1 < 0 && nums[mid] > nums[mid+1] && mid + 1 < n)
                return mid;
            else if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if (nums[mid] < nums[mid-1] && nums[mid] > nums[mid+1])
                right = mid-1;
            else
                left = mid+1;
        }
        return nums[0];
    }
};

// 1 2 3 8 7 6 5 4 3 2 1