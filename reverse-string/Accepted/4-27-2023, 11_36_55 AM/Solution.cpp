// https://leetcode.com/problems/reverse-string

class Solution {
public:
    void rev_str_helper(vector<char>& s, int start, int end) {
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    void reverseString(vector<char>& s) {
        rev_str_helper(s, 0, s.size()-1);
    }
};