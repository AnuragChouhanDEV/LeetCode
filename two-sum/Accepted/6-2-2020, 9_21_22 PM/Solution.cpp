// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> res(2,0);
        int diff;
        for (int i = 0; i < nums.size();++i) {   
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size();++i) {   
            diff = target - nums[i];
            if (m[diff] && m[diff] != i) {
                res[0] = i;
                res[1] = m[diff];
            }
        }
        return res;
    }
};