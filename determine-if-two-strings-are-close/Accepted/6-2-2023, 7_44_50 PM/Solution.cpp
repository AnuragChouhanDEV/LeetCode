// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        unordered_set<char> ma2(word2.begin(), word2.end());
        unordered_set<char> ma1(word1.begin(), word1.end());

        for (auto a:word1) v1[a-'a']++;
        for (auto a:word2) v2[a-'a']++;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return (ma1 == ma2 && v1==v2);

    }
};