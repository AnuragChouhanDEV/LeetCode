// https://leetcode.com/problems/arithmetic-subarrays/description/?envType=daily-question&envId=2023-11-23

class Solution {
public:
    bool check_arithmetic(vector<int> v) {
        if (v.size() < 2)
            return true;
        int diff = v[1]-v[0];
        for (int i = 2; i < v.size(); ++i) {
            if ((v[i] - v[i-1]) != diff)
                return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> res(m,false);
        for (int i = 0 ; i < m; ++i) {
            vector<int> v;
            v.assign(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(v.begin(),v.end());
            res[i] = check_arithmetic(v);
        }
        return res;
    }
};