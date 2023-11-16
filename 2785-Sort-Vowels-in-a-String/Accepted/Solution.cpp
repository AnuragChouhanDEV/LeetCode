// https://leetcode.com/problems/sort-vowels-in-a-string/description/?envType=daily-question&envId=2023-11-13

class Solution {
public:
    bool vowelOrConsonant(char x) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o'
            || x == 'u' || x == 'A' || x == 'E' || x == 'I'
            || x == 'O' || x == 'U')
            return true;
        return false;
    }
    string sortVowels(string s) {
        // <char <count, index>>
        vector<char> v;
        for (int i = 0; i < s.size(); ++i) {
            if (vowelOrConsonant(s[i])) {
                v.push_back(s[i]);
            }
        }
        sort(v.begin(), v.end());
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (vowelOrConsonant(s[i])) {
                s[i]=v[j];
                ++j;
            }
        }
        return s;
    }
};