// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    bool is_vowel(char c) {
        switch(c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
        return false;
    }
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size()-1;
        while (left < right) {
            while (left < right && !is_vowel(s[left])) left++;
            while (left < right && !is_vowel(s[right])) right--;
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};