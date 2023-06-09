// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool is_palindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if(isupper(s[i])) {
                s[i] = tolower(s[i]);
                continue;
            }
            else if (islower(s[i]) || isdigit(s[i])) {
                continue;
            } else {
                s.erase(i,1);
                i--;
            }
        }
        //cout << s << endl;
        return is_palindrome(s);
    }
};