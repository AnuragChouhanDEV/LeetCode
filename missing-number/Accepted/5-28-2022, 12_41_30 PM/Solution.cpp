// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        n = (n * (n+1))/2;
        for (int i = 0; i < nums.size(); ++i) {
            n -= nums[i];
        }
        return n;
    }
};

//3 0 1
//6 - 4 = 2

//0 1
//3 - 1 = 2

// 9 6 4 2 3 5 7 0 1
//45 - 15 - 15 - 7 = 8