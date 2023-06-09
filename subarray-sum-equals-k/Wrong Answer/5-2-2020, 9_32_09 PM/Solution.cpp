// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //For fast I/O in C++
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<int,int> map;
        int n = nums.size();
        if (n == 0)
            return 0;
        
        int sum = 0;
        int i = 0;
        int count = 0;
        
        while (i < n) {
            sum += nums[i];
            
            if (sum == k)
                count++;
            
            if (map.find(sum - k) != map.end())
                count++;
            
            map[sum]++;
            ++i;
                
        }
        
        return count;
    }
};