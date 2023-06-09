// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> ma;
        for (int i = 0; i < nums.size(); ++i) {
            if (ma[nums[i]] >= ((nums.size()-1)/2))
                return nums[i];                                
            ma[nums[i]] += 1; 
        }
        return -1;
    }
};