// https://leetcode.com/problems/count-of-smaller-numbers-after-self

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int count = 0;
        for (int i = nums.size()-2; i >= 0; --i) {
            if (nums[i] > nums[i+1]) {
                count++;
            }
            res[i] = count;
        }
        return res;
    }
};