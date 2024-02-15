// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long res = 0;
        sort(nums.begin(),nums.end());
        for(auto it : nums) 
            res += it;
        for(int i = nums.size() - 1; i > 1; i--){
            res -= nums[i];
            if(res > nums[i]){
                return res + nums[i];
            }
        }
        return -1;
    }
};