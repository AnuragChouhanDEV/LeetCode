// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        unordered_map<char,int> ma1;
        unordered_map<char,int> ma2;

        for (auto a:word1) ma1[a]++;
        for (auto a:word2) ma2[a]++;

        if (ma1 == ma2) return true;
        else {
            int i = 0;
            for (auto it:ma1) {
                auto it2 = ma2.find(it.first);
                if (it2 == ma2.end()) {
                    return false;
                }
            }
        }
        return true;
    }
};