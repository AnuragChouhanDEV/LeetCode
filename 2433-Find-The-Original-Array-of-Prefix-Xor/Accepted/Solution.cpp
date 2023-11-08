// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/?envType=daily-question&envId=2023-10-31

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res(pref.size(), 0);
        int n = pref.size();
        for (int i = n-1; i>0; --i) {
            res[i] = pref[i]^pref[i-1];
        }
        res[0] = pref[0];
        return res;
    }
};