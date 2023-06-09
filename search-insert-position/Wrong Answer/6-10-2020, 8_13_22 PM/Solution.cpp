// https://leetcode.com/problems/search-insert-position

class Solution {
    int b_search(vector<int>& nums, int left, int right, int target) {
        int mid;
        if (right > left) { 
            cout << left << " " << right << endl;
            mid = left + (right - left) / 2; 

            if (nums[mid] == target) 
                return mid; 

            if (nums[mid] > target) 
                return b_search(nums, left, mid - 1, target); 
 
            return b_search(nums, mid + 1, right, target); 
        } else
        return left+1;
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if (target <= nums[0])
            return 0;
        if (target == nums[0])
            return 1;
        return b_search(nums, 0, len - 1, target);
    }
};