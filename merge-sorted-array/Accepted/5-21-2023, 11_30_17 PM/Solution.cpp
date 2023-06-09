// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            nums1.resize(n);
            for (int i = 0; i < n; ++i)
                nums1[i] = nums2[i];
            return;
        }
        /*
        m = m+n;
        nums1.resize(m);
        for (int i = m-n,j=0; i < m; ++i,++j) {
            nums1[i] = nums2[j];
        }
        */
        
        int i = m-1;
        int j = n-1;
        int idx = m+n-1;
        while (i >= 0 && j>=0) {
            if (nums1[i] >= nums2[j]) {
                nums1[idx--] = nums1[i--];
            } else {
                nums1[idx--] = nums2[j--];
            }
        }
        while (j>=0) {
            nums1[idx--] = nums2[j--];
        }
    }
};