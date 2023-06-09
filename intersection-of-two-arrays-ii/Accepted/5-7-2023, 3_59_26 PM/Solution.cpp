// https://leetcode.com/problems/intersection-of-two-arrays-ii

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> ma;
        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i)
            ma[nums1[i]]++;
        for (int i = 0; i < nums2.size(); ++i) {
            auto it = ma.find(nums2[i]);
            if (it != ma.end() && it->second) {
                res.push_back(nums2[i]);
                it->second--;
            }
        }
        return res;
    }
};