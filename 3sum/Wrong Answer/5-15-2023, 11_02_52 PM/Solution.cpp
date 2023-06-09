// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; ++i) {
            
            int low = i+1;
            int hi = nums.size()-1;
            while(low < hi) {
                vector<int> v;
                if (nums[i]+nums[low]+nums[hi] == 0) {
                    v.push_back(nums[i]);
                    v.push_back(nums[low]);
                    v.push_back(nums[hi]);
                    res.insert(v);
                }
                low++;hi--;
            }
        }
        vector<vector<int>> result(res.begin(), res.end());
        return result;    
    }
};