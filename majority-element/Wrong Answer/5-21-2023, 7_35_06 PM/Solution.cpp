// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> ma;
        for (int i = 0; i < nums.size(); ++i) {
            if (ma.find(nums[i]) != ma.end()) {
                if (ma[nums[i]] >= nums.size()/2)
                    return nums[i];
            }
            ma[nums[i]]++;
        }
        return 0;
    }
};