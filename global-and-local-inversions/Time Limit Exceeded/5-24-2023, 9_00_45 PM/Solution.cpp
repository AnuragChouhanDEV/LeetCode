// https://leetcode.com/problems/global-and-local-inversions

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int count_local_inv = 0;
        int count_global_inv = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i-1])
                count_local_inv++;
        }
        for (int i = 0; i < n; ++i) {
            int temp = nums[i];
            for (int j = i+1; j < n; ++j) {
                if (nums[j] < temp)
                    count_global_inv++;
                if (count_global_inv > count_local_inv)
                    return false;
            }
        }
        //cout << count_local_inv << " " << count_global_inv<<endl;
        if (count_local_inv == count_global_inv) return true;
        return false;
    }
};