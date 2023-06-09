// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid = -1;
        //cout << low << " " << high << endl;
        if (nums[0] > target)
            return 0;
        while (low <= high) {
            mid = low + (high-low) / 2;
            //cout << mid << endl;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid+1;
            else if (nums[mid] > target)
                high = mid-1;
        }
        return mid+1;
    }
};