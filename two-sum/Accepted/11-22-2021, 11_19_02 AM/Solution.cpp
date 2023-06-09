// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int,int> ma;
        for (int i = 0; i < nums.size();++i) {
            auto it = ma.find(target-nums[i]);
            if (it != ma.end()) {
                res.push_back((*it).second);
                res.push_back(i);
                break;
            }
            //cout << i << " " << nums[i] << endl;
            ma[nums[i]] = i;
        }
        return res;
    }
};