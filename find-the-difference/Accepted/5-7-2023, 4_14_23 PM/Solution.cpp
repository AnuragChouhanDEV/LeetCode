// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch = 0;
        for (auto c:t) ch ^= c;
        for (auto c:s) ch ^= c;
        return ch;
    }
};