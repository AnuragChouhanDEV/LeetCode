// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> visited(nums.size()+1, -1);
        for (int i = 0; i < nums.size(); ++i) {
            visited[nums[i]]++;
        }
        for (int i = 0; i < visited.size(); ++i)
            if (visited[i] == -1)
                return i;
        return nums.size();
    }
};