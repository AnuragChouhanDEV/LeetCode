// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element;
        int cnt = 0;
        for(auto num:nums) {
            if (!cnt) element = num;
            if (element == num) cnt++;
            else cnt--;
        }
        return element;
    }
};