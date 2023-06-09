// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = nums.size()-1;

        while(white <= blue) {
            switch (nums[white]) {
                case 0:
                    swap(nums[red],nums[white]);
                    red++;
                    white++;
                    break;
                case 1:
                    white++;
                    break;
                case 2:
                    swap(nums[white], nums[blue]);
                    blue--;
                    break;
                default:
                    return;
            }
        }
    }
};