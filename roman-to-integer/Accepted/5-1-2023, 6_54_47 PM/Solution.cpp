// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int I = 1;
    int V = 5;
    int X = 10;
    int L = 50;
    int C = 100;
    int D = 500;
    int M = 1000;
    int char_to_int(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
    int romanToInt(string s) {
        int res;
        int max_num = 0;
        if (s.size() == 0)
            return 0;
        if (char_to_int(s[s.size()-1])) {
            res = char_to_int(s[s.size()-1]);
            max_num = res;
        }
        for (int i = s.size()-2; i >= 0; --i) {
            int temp = char_to_int(s[i]);
            if (temp < max_num) {
                res-=temp;
                continue;
            } else {
                res+=temp;
                max_num = temp;
            }
        }
        return res;
    }
};