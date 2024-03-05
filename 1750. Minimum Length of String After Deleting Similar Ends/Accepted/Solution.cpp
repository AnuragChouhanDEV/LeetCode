// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05

#pragma GCC optimize("O3,unroll-loops") #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:
    int minimumLength(string s) {
        ios_base::sync_with_stdio(false);
        int left = 0;
        int right = s.size() - 1;

        while (left < right && s[left] == s[right]) {
            char ch = s[left];
            while (left <= right && s[left] == ch) {
                left++;
            }
            while (right >= left && s[right] == ch) {
                right--;
            }
        }

        return right - left + 1;
    }
};