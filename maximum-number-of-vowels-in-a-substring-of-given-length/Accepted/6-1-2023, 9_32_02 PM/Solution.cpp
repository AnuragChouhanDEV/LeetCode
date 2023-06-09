// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

class Solution {
public:
    bool is_char_vowel(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int vowelcount = 0;
        int left = 0;
        int right = 0;
        int tmpcount = 0;
        while (right < k) {
            if (is_char_vowel(s[right]))
                vowelcount++;
            ++right;
        }
        if(vowelcount == k)
            return k;
        tmpcount = vowelcount;
        while(right < s.size()) {
            if (vowelcount == k) return k;
            if (is_char_vowel(s[right++])) tmpcount++;
            if (is_char_vowel(s[left++])) tmpcount--;
            vowelcount = max(vowelcount,tmpcount);
        }
        return vowelcount;
    }
};