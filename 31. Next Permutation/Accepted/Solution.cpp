// https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        for (int i = n-2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                idx = i;
                break;
            }
        }
        for (int i = n-1; i>=idx && idx != -1;--i) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }
        reverse(nums.begin()+idx+1, nums.end());
    }
};
/*
[1,2,3,7,6,5,4,3]
1 2 4 7 6 5 3 3
1 2 4 3 3 5 6 7
*/