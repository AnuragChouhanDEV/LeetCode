// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/?envType=daily-question&envId=2023-11-19

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = n-1; i > 0; --i) {
            if (nums[i] != nums[i-1]) {
                res += n - i;
            }
        }
        return res;
    }
};