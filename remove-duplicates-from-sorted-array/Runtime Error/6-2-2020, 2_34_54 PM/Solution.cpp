// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1;
        for (int i = 0; i < nums.size() - 1;++i) {
            if (nums[i] != nums[i+1])
                nums[idx++] = nums[i+1];
        }
        return idx;
    }
};