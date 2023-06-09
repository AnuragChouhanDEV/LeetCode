// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> pair;
        if (nums.size() == 0)
            return false;
        for (int i = 0; i < nums.size(); ++i) {
            pair[nums[i]]++;
            if (pair[nums[i]] > 1)
                return true;    
        }
        return false;
    }
};