// https://leetcode.com/problems/next-greater-element-i/description/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> vec(n, -1);
        // store next greated element in vec
        for (int i = n-2; i >= 0; --i) {
            int j = i+1;
            while (j < n && nums2[i] > nums2[j]) j++;
            if (j == n) continue;
            vec[i] = nums2[j];
        }
        // element, index
        unordered_map<int,int> ma;
        for (int i = 0; i < n; ++i)
            ma[nums2[i]]=i;
        vector<int> res;
        for (auto it:nums1) {
            res.push_back(vec[ma[it]]);
        }
        return res;
    }
};