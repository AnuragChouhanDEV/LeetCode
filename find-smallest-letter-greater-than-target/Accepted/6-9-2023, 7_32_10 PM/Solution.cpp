// https://leetcode.com/problems/find-smallest-letter-greater-than-target

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ch = 'z'+1;
        for (int i = letters.size()-1; i >= 0; --i) {
            char a = letters[i];
            if (a < ch && a > target) ch = a;
        }
        return ch == 'z'+1 ? letters[0]:ch; 
    }
};