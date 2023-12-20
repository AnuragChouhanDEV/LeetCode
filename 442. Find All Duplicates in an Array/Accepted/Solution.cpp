// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while(i < n) {
            if(nums[i] == i+1) i++;
            else {
                int position = nums[i] - 1;
                if(nums[i] == nums[position]) i++;
                else swap(nums[i], nums[position]);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
            if(nums[i] != i+1)
                ans.push_back(nums[i]);
        return ans;     
    }
};
/*
4 3 2 7 8 2 3 1

i 0 correct 1 nums[i] 4  position 3  swapped i and position
7 3 2 4 8 2 3 1 

i 0 correct 1 nums[i] 7  position 6  swapped i and position
3 3 2 4 8 2 7 1 

i 0 correct 1 nums[i] 3  position 2  swapped i and position
2 3 3 4 8 2 7 1 

i 0 correct 1 nums[i] 2  position 1  swapped i and position
3 2 3 4 8 2 7 1 

i 0 correct 1 nums[i] 3  position 2 
i 1 correct 2 nums[i] 2 
i 2 correct 3 nums[i] 3 
i 3 correct 4 nums[i] 4 
i 4 correct 5 nums[i] 8  position 7  swapped i and position
3 2 3 4 1 2 7 8 

i 4 correct 5 nums[i] 1  position 0  swapped i and position
1 2 3 4 3 2 7 8 

i 4 correct 5 nums[i] 3  position 2 
i 5 correct 6 nums[i] 2  position 1 
i 6 correct 7 nums[i] 7 
i 7 correct 8 nums[i] 8 
*/