// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<pair<int,int>> pair(nums.size() - 1, make_pair(-1,-1));
        for (int i = 0; i < nums.size(); ++i) {
            pair.push_back(make_pair(nums[i],pair[i].second+1));
            if (pair[i].second > 0)
                return false;    
        }
        return true;
    }
};