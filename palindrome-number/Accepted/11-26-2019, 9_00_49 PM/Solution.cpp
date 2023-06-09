// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        int divisor = 1;
        while ((x/divisor) >= 10)
            divisor *= 10;
        if (x < 0)
            return false;
        while (x != 0) {
            int first = x/divisor;
            int last = x%10;
            // printf("%d ", x);
            if (first != last)
                return false;
            x = (x % divisor)/10;
            divisor = divisor/100;
        }
        return true;
    }
};