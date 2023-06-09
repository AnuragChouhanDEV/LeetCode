// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words

class Solution {
public:
    bool self_palindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;right--;
        }
        return true;
    }
    bool pair_palindrome(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int lefts1 = 0;
        int rights2 = s2.size()-1;
        while (lefts1 < s1.size() && rights2 >= 0) {
            if (s1[lefts1] != s2[rights2])
                return false;
            lefts1++;rights2--;
        }
        return true;
    }
    int longestPalindrome(vector<string>& words) {
        // self palindrome maxsize = size of it
        // 2 diff palindrome maxsize_size of both
        int max_size = 0;
        int self_pld_idx = -1;
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            if (self_palindrome(word)) {
                if (max_size < word.size()) {
                    self_pld_idx = i;
                    max_size = word.size();
                }
            }
        }
        if (self_pld_idx != -1) words.erase(words.begin()+self_pld_idx);
        vector<unordered_map<char, int>> vec;
        for (int i = 0; i < words.size(); ++i) {
            unordered_map<char, int> tmp;
            string word = words[i];
            for (char c:word)
                tmp[c]++;
            for (int j = 0; j < vec.size(); ++j) {
                if (vec[j] == tmp) {
                    if (pair_palindrome(word, words[j])) {
                        max_size = max(max_size, max_size + (((int)words[j].size()) * 2));
                        //vec.erase(vec.begin()+j);
                    }
                }
            }
#if 0          
            auto it = ma.find(tmp)
            if (it != ma.end()) {
                if (pair_palindrome(word, words[it.second])) {
                    max_size = max(max_size, max_size + word.size() * 2);
                    ma.erase(it.first);
                }
            } else
#endif
                vec.push_back(tmp);        
        }
        return max_size;
    }
};