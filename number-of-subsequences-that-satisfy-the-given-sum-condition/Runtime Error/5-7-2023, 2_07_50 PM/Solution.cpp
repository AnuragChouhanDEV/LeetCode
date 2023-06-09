// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9+7;
        int res = 0;
        vector<int> exps(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            exps[i] = (2*exps[i-1]) % mod;
            //cout << exps[i] << " ";
        }
        cout << endl;
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size()-1;
        while(left <= right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                //cout << " here left " << left <<" right "<<right << endl;
                res = res + exps[right - left];
                left++;
            }
        }
        return res;
    }
};