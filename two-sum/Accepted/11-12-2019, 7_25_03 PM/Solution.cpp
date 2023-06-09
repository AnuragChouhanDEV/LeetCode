// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Key is the number and value is its index in the vector.
        unordered_map<int, int> hash;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            int num_to_find = target - nums[i];
            
            //if numberToFind is found in map, return them
            if (hash.find(num_to_find) != hash.end()) {
                result.push_back(hash[num_to_find]);
                result.push_back(i);
                return result;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};