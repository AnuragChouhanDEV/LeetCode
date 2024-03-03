// https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
    std::vector<int> result(n);

    int left = 0, right = n - 1, index = n - 1;

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            result[index--] = leftSquare;
            left++;
        } else {
            result[index--] = rightSquare;
            right--;
        }
    }

    return result;
    }
};
/*
16 1 0 9 100

49 9 4 9 121
9 9 4 49 121
4 9 9 49 121

-5 -3 -2 -1
25 9 4 1
1 9 4 25
*/