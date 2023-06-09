// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> ma;
        int n = nums.size();
        if (n == 1) return nums[0];
        for (int i = 0; i < n; ++i) {
            if (ma.find(nums[i]) != ma.end()) {
                if (ma[nums[i]] >= n/2)
                    return nums[i];
            }
            ma[nums[i]]++;
        }
        return 0;
    }
};