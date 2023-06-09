// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;int right = nums.size()-1;
        int mid = 0;
        while (left < right) {
            mid = left + (right-left)/2;
            //cout << "mid " << mid << " left " << left << " right " << right << endl;
            
            if (nums[mid] > nums[right]) left = mid+1;
            else if (nums[mid] < nums[right]) right = mid;
            else right--;
        }
        return nums[left];
    }
};