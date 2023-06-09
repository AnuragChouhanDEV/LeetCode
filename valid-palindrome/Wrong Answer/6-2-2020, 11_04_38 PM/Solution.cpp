// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        //cout << s << endl;
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        while(i < j) {
            while(i<j && (s[i] >= 'a' && s[i] <= 'z'))
                ++i;
            while(i<j && (s[j] >= 'a' && s[j] <= 'z'))
                --j;
            if(i<j && (s[i++] != s[j--]))
                return false;
        }
        return true;
    }
};