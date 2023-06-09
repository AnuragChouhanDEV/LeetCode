// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto i = nums.begin(); i != nums.end(); i++) {
           // printf ("%p -> %d, ",i , *i);
            ret = ret ^ (*i);
        }
        return ret;
        
    }
};