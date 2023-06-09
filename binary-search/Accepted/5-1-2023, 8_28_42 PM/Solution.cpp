// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            int x = nums[mid];
            if (x == target) return mid;
            if (x < target) left = mid+1;
            if (x > target) right = mid-1;
        }
        return -1;
    }
};