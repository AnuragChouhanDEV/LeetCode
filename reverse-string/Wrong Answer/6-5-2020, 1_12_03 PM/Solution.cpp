// https://leetcode.com/problems/reverse-string

class Solution {
    void swap(char &a, char &b) {
        char t = a;
        a = b;
        b = t;
    }
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for(int i = 0; i < len/2;++i) {
            swap(s[i],s[len-1]);
            len--;
        }
    }
};