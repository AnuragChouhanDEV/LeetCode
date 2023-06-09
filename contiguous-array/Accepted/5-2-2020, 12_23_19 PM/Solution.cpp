// https://leetcode.com/problems/contiguous-array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> map;
        int sum = 0;
        int longest_sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i]?1:-1;
            
            if (sum == 0) {
                if (longest_sum < i+1)
                    longest_sum = i+1;
            } else if (map.find(sum) != map.end()) {
                if (longest_sum < i-map[sum])
                    longest_sum = i-map[sum];
            } else {
                map[sum] = i;
            }
            
        }
        return longest_sum;
    }
};