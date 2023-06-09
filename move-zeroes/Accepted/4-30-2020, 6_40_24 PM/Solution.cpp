// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator count = nums.begin();

        //printf("begin %p, end = %p \n", nums.begin(), nums.end());
        for (auto i = nums.begin(); i != nums.end(); ++i) {
            if (*i != 0) {
                *count = *i; // here count is  
                                   // incremented 
                count ++;
            }
        }
        
       // int count = 0;  // Count of non-zero elements 
  

    while (count < nums.end()) {
        *count = 0; 
        count ++;
    }
    }
};