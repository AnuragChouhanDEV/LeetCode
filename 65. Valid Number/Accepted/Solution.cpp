// https://leetcode.com/problems/valid-number/

class Solution {
public:
    bool isNumber(string s) {
        int index = 0;
        int digits = 0;
        if (!s.size()) return false;

        // check for first '+' or '-' e.g "+3.14"
        if (s[index] == '+' || s[index] == '-') index++;

        // increment the digits e.g "0089"
        while (index < s.size() && isdigit(s[index])) {
            digits++;
            index++;
        }

        // check for '.' e.g "+3.14"
        if (index < s.size() && s[index] == '.') {
            index++;
            // check for digits after '.' e.g "+3.14"
            while (index < s.size() && isdigit(s[index])) {
                digits++;
                index++;
            }
        }

        // check for 'e' or 'E' e.g "3e+7"
        if (index < s.size() && (s[index] == 'e' || s[index] == 'E')) {
            index++;

            // check for '+' or '-' after and e or E e.g "+6e-1"
            if (index < s.size() && (s[index] == '+' || s[index] == '-')) 
                index++;

            // if index == size or a non digit e.g "99e2.5"
            if (index == s.size() || !isdigit(s[index])) {
                return false;
            }

            // check for digits after '+' or '-' e.g "3e+7"
            while (index < s.size() && isdigit(s[index])) {
                index++;
            }
        }
        // return if reached to the end and we have atleast 1 digit
        return index == s.size() && digits;
    }
};