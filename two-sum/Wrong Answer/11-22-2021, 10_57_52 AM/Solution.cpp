// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int i = 0;
        int j = nums.size()-1;
        while (i < j) {
            if (nums[i] + nums[j] == target) {
                res.push_back(i);
                res.push_back(j);
                break;
            } else if (nums[i] + nums[j] > target) {
                j--;
            } else if (nums[i] + nums[j] < target) {
                i++;
            }
        }
        return res;
    }
};