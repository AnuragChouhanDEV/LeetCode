// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto it:nums) {
            if (it > 0)
                s.insert(it);
        }
        for (int i = 1; i <= nums.size();++i) {
            if (s.find(i) == s.end())
                return i;
        }
        return nums.size()+1;
    }
};