// https://leetcode.com/problems/guess-number-higher-or-lower

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if (n == 1) return 1;
        int left = 1;
        int right = n;
        int mid;
        while (left < right) {
            mid = (right + left)/2; // 5
            //cout << left <<" "<< right << " "<< mid << endl;
            int g = guess(mid); // 1
            if (g == 0)
                return mid;
            else if (g == -1) {
                right = mid;
            } else if (g == 1) {
                left = mid; // 6
            }
        }
        return mid;
    }
};