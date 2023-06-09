// https://leetcode.com/problems/maximum-erasure-value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> ss;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ss.insert(nums[i]);
        }
        for(auto s:ss) {
            sum += s;
        }
        return sum;
    }
};