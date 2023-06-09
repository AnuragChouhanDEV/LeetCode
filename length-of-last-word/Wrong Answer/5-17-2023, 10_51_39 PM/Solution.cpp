// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int start = s.size()-1;
        for (int i = s.size()-1; i>= 0; i--) {
            start = i;
            if (s[i] == ' ') {
                
                continue;
            }
            while (i > 0 && s[i] != ' ') --i;
            if (i >= 0 && s[i] == ' ') {return start-i;}
            break;
        }
        return s.size();
    }
};