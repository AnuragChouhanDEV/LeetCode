// https://leetcode.com/problems/max-number-of-k-sum-pairs

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 1 && nums[0] == k) return 1;
        int out = 0;
        int left = 0;
        int right = n-1;
        while (left < right) {
            if(nums[left]+nums[right] == k) {
                out++;left++;right--;
            }
            else if (nums[left]+nums[right] < k) left++;
            else right--;
        }
        return out;
    }
};