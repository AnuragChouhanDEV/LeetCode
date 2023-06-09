// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_size = INT_MAX;
        int start = 0;
        int i = 0;
        int sum = 0;
        while (i < nums.size()) {
            sum += nums[i];
            //cout << sum << endl;
             
            while (target <= sum) {
                //cout << target << " " << sum << endl;
                if (target == sum) {
                    min_size = min(min_size, i+1 - start);
                }
                sum -= nums[start++];
            }
            ++i;
        }
        return min_size != INT_MAX ? min_size : 0;
    }
};