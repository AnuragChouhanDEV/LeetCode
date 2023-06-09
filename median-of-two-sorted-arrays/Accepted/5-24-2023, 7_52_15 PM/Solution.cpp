// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m>n)
            return findMedianSortedArrays(nums2,nums1);
        int left = 0;
        int right = m;
        while (left <= right) {
            int p1 = (left + right)/2;
            int p2 = (m+n+1)/2 - p1;
            int max_l1 = (p1==0) ? INT_MIN:nums1[p1-1];
            int min_r1 = (p1==m) ? INT_MAX:nums1[p1];
            int max_l2 = (p2==0) ? INT_MIN:nums2[p2-1];
            int min_r2 = (p2==n) ? INT_MAX:nums2[p2];
            //cout << left << " " << right << " "<< endl;
            //cout << p1 << " " << p2 <<" "<< max_l1 << " " << min_r1 << " " << max_l2 << " " << min_r2 << endl;
            if ((max_l1 <= min_r2) && (max_l2 <= min_r1)) {
                if ((m+n)%2) {
                    return (double) max(max_l1,max_l2);
                } else {
                    //cout << " reached here " << endl;
                    return (double)((max(max_l1,max_l2)+min(min_r1,min_r2))/2.0);
                }
            } else if (max_l1 > min_r2) {
                //cout << "why here " << endl;
                right = p1-1;
            } else {
                //cout << "i have no idea" << endl;
                left = p1+1;
            }
        }
        return -1;
    }
};