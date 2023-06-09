// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        string result;
        int left = 0;
        int right = s.size();
        while(left < right) {
            while (left < right && s[left] == ' ') left++;
            if (left >= right) break;
            int j = left+1;
            while (j < right && s[j] != ' ') j++;
            string sub = s.substr(left, j-left);
            if(result.size() == 0) result = sub;
            else result = sub + " " + result;
            left = j+1;
        }
        return result;
    }
};