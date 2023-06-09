// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr(2);
        map<int,int> mymap;
        
        for (int i = 0; i < nums.size();++i) {
            mymap[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size();++i) {
            int cmp = target - nums[i];
            if (mymap[cmp] && mymap[cmp] != i) {
                arr[0] = i;
                arr[1] = mymap[cmp];
            }
        }
        return arr;
    }
};