// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int max = 0;
        int curr = 0;
        
        for (int i = 0; i < n; ++i) {
            int id = nums[i]%n;
            nums[id] += n;
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > curr) {
                curr = nums[i];
                max = i;
            }
            nums[i] %= n;
        }
        return max;
    }
};