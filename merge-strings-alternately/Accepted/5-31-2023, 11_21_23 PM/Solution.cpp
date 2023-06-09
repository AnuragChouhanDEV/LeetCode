// https://leetcode.com/problems/merge-strings-alternately

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int i = 0;int j = 0;
        while (i < word1.size() && j < word2.size()) {
            res = res+word1[i++]+word2[j++];
        }
        if (i < word1.size()) res += word1.substr(i, word1.size()-i);
        if (j < word2.size()) res += word2.substr(j, word2.size()-j);
        return res;
    }
};