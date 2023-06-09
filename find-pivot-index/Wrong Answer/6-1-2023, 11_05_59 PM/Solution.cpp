// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int idx = 0;
        int right_sum = 0;
        int left_sum = 0;
        //for (int i = 0; i <= idx; ++i) left_sum += nums[i];
        for (int i = 0; i < nums.size(); ++i) right_sum += nums[i];
        while (left_sum < right_sum) {
            //cout << left_sum << " " << right_sum<<endl;
            if (left_sum + nums[idx] == right_sum)
                return idx;
            else if (left_sum + nums[idx] < right_sum) {
                left_sum += nums[idx];
                right_sum -= nums[idx];
                idx++;
            } else 
                idx--;
        }
        return -1;
    }
};