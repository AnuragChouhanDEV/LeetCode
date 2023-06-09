// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> ma;
        vector<int> ret;
        int sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            if (ma.find(target-nums[i]) != ma.end()) {
                ret.push_back(i);
                ret.push_back(ma[target-nums[i]]);
            }
            ma[nums[i]] = i;
        }
        return ret;
/*
        int sz = nums.size();
        vector<int> ret;

        for (int i = 0; i < sz; ++i) {
            for (int j = i+1; j < sz;++j) {
                if (nums[i]+nums[j] == target) {
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }
        return ret;
*/
    }
};