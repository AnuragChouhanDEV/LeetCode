// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        if (l == h && nums[l] == target)
            return 0;
        while (l < h) {
            int mid = l + (h-l)/2;
            //cout << mid <<", "<< l << ", "<< h << endl;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                h = mid-1;
            else if (nums[mid] < target)
                l = mid+1;
        }
        return -1;
    }
};