// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/?envType=daily-question&envId=2023-11-17

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxe = 0;
        for (int i = 0; i < (nums.size()/2); ++i) {
            maxe = max(maxe, nums[i]+nums[nums.size()-i-1]);
        }
        return maxe;
    }
};