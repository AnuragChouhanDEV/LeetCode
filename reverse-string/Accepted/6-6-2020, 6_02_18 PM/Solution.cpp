// https://leetcode.com/problems/reverse-string

class Solution {
    void swap(char &a, char &b) {
        char t = a;
        a = b;
        b = t;
    }
    void rev(vector<char>& s, int left, int right) {
        if (left >= right)
            return;
        swap(s[left], s[right]);
        rev(s, left+1, right -1);
    }
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        rev(s, 0, len -1);
    }
};
#if 0
class Solution {
    void swap(char &a, char &b) {
        char t = a;
        a = b;
        b = t;
    }
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for(int i = 0; i < len;++i) {
            swap(s[i],s[len-1]);
            len--;
        }
    }
};
#endif