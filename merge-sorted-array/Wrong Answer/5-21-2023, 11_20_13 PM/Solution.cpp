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
        for (int i = m-n,j=0; i < m; ++i,++j) {
            nums1[i] = nums2[j];
            cout << nums1[i] << " ";
        }
        // 4,5,6,1,2,3
        // 1,5,6,4,2,3
        // 1,4,6,5,2,3
        // 1,2,6,5,4,3
        // 1,2,4,5,6,3
        // 1,2,3,5,6,4
        
        int left = 0;
        int right = m-n;
        while (left < m-n && right < m) {
            //cout << " left " << left << " right "<<right<<endl;
            if (nums1[left] <= nums1[right]) 
                left++;
            else if (nums1[left] > nums1[right])
                swap(nums1[left], nums1[right++]);
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