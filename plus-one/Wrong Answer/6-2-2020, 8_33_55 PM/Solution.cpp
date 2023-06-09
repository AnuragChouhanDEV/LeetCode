// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        if (digits.size() == 0)
            return digits;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (i == digits.size() - 1)
                digits[i] = digits[i] + 1 + carry;
            if (digits[i] == 10) {
                digits[i] = 0;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        if (carry) {
            digits.resize(digits.size());
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};