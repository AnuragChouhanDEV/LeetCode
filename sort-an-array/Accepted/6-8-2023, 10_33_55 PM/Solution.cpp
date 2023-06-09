// https://leetcode.com/problems/sort-an-array

class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        if (left < right) {
            int l = left;
            int r = mid+1;
            int k = 0;
            vector<int> tmp(right-left+1, 0);
            while (l <= mid && r <= right) {
                if (nums[l] < nums[r]) {
                    tmp[k] = nums[l];
                    k++;l++;
                } else {
                    tmp[k] = nums[r];
                    k++;r++;
                }
            }
            while (l <= mid) {
                    tmp[k] = nums[l];
                    k++;l++;
            }
            while (r <= right) {
                    tmp[k] = nums[r];
                    k++;r++;
            }
            for (int i = left; i <= right; ++i)
                nums[i] = tmp[i-left];
        }
    }
    void merge_sort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right-left)/2;
            merge_sort(nums, left, mid);
            merge_sort(nums, mid+1, right);
            merge(nums, left, mid, right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size()-1);
        return nums;
    }
};