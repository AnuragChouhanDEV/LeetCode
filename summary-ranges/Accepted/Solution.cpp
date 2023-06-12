// https://leetcode.com/problems/summary-ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;
        if (n == 0) return res;
        int left = nums[0];
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i == nums.size()-1 || nums[i]+1 != nums[i+1]) {
                if (nums[i] != left) 
                    res.push_back(to_string(left) + "->" + to_string(nums[i]));
                else 
                    res.push_back(to_string(left));
                if (i != nums.size()-1) 
                    left = nums[i+1];
            }
        }
        return res;
    }
};