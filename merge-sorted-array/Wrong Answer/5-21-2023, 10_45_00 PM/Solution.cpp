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
        m = m+n;
        nums1.resize(m);
        for (int i = m-n; i < m; ++i) {
            nums1[i] = nums2[m-i-1];
        }
        
        int left = 0;
        int right = m-1;
        while (left < right) {
            //cout << " left " << left << " right "<<right<<endl;
            if (nums1[left] <= nums1[right]) left++;
            else swap(nums1[left], nums1[right]);
        }
        
    }
};


// 1 2 3 0 0 0      2 5 6
// 1 2 3 6 5 2
// 1 2 2 3 5 6

/*
while (left < m-n && right < m) {
    if left <= right
    left++;
    else 
    swap
}
*/