// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/

class Solution {
public:
    //vector<int> res;
    pair<int,int> findMinMax(const std::vector<int>& nums) {
        int firstMin = INT_MAX, secondMin = INT_MAX;
        int firstMax = INT_MIN, secondMax = INT_MIN;

        for (const auto& num : nums) {
            // Check for minimum elements
            if (num <= firstMin) {
                secondMin = firstMin;
                firstMin = num;
            } else if (num < secondMin && num != firstMin) {
                secondMin = num;
            }

            // Check for maximum elements
            if (num >= firstMax) {
                secondMax = firstMax;
                firstMax = num;
            } else if (num > secondMax && num != firstMax) {
                secondMax = num;
            }
        }
        return {(firstMin * secondMin), (firstMax * secondMax)};
    }
    int maxProductDifference(vector<int>& nums) {
        pair<int,int> p = findMinMax(nums);
        return (p.second - p.first);
    }
};
/*
5 6 2 7 4

2 4 5 6 7

4 2 5 9 7 4 8
2 4 4 5 7 8 9

*/