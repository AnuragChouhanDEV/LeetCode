// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int element1=INT_MAX;
        int element2=INT_MAX;
        int cnt1=0;
        int cnt2=0;
        if (nums.size() < 3) return nums;
        for(auto num:nums) {
            if (!cnt1) element1 = num;
            else if (!cnt2) element2 = num;
            else if (element1 == num) cnt1++;
            else if (element2 == num) cnt2++;
            else {
                cnt1--;cnt2--;
            }
        }
        if (element1 != INT_MAX && element2 != INT_MAX) return {element1,element2};
        else if (element1 != INT_MAX) return {element1};
        else return {element2};
    }
};