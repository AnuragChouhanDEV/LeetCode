// https://leetcode.com/problems/count-nice-pairs-in-an-array/description/?envType=daily-question&envId=2023-11-21

class Solution {
public:
    int rev(int num) { 
        string str = to_string(num); 
        reverse(str.begin(), str.end()); 
        num = stoll(str); 
        return num; 
    }

    int countNicePairs(vector<int>& nums) {
        int count = 0;
        unordered_map<int,int> ma;
        int M = 1e9+7;
        for (int i = nums.size()-1; i >= 0; --i) {
            int temp = nums[i] - rev(nums[i]);
            if (ma.count(temp) == true)
                count = (count+ma[temp])%M;
            ma[temp]++;
            
        }
        return count;
    }
};
/*
[13,10,35,24,76]
 18 9 18 18 9

[42,11,1,97]
 18 0 0 18
*/