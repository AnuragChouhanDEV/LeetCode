// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool one = false;
        int n = nums.size();
        if (n == 1 && nums[0] != 1) {
            return 1;
        }
        if (n==1 && nums[0] == 1)
            return 2;
        for (auto it:nums) {
            if(it==1) 
                one = true;
        }
        if (!one)
            return 1;
        for (int i = 0; i < n;++i)
            if ((nums[i] <= 0) || (nums[i] > n))
                nums[i] = 1;
        for (int i = 0; i < n; ++i) {
            int x = abs(nums[i]);
            if (nums[x-1] > 0)
                nums[x-1] *= -1;
        }
        for (int i = 0; i < n; ++i)
            if (nums[i] > 0)
                return i+1;
        return n+1;
/*
        unordered_set<int> s;
        for (auto it:nums) {
            if (it > 0)
                s.insert(it);
        }
        for (int i = 1; i <= nums.size();++i) {
            if (s.find(i) == s.end())
                return i;
        }
        return nums.size()+1;
*/
    }
};