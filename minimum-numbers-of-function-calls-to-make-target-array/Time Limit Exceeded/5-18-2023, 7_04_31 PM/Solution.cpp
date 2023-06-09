// https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size = nums.size();
        int operations = 0;
        if (nums.size() == 1 && nums[0] == 0)
            return 0;
        while(nums.size()) {
            for (int i = 0; i < nums.size(); ++i) {
                //nums[i] >>= 1;
                if ((nums[i] & 0xffffffff) == 1) {
                    //cout << nums[i] << endl;
                    nums.erase(nums.begin()+i);
                    operations++;
                    --i;
                    continue;
                } else if (nums[i] & 1) {
                    nums[i] &= 0xfffffffe;
                    operations++;
                    continue;
                } else if ((nums[i] & 0xffffffff) == 0) {
                    nums.erase(nums.begin()+i);
                    //operations++;
                    --i;
                }
            }
            for (int i = 0; i < nums.size(); ++i)
                nums[i] >>= 1;
            if (nums.size()) operations++;
        }
        return operations;
    }
   
};