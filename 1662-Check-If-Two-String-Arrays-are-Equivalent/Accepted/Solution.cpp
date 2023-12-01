// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/?envType=daily-question&envId=2023-12-01

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int res = 0;
        string str1, str2;
        for (auto it:word1)
            str1 += it;
        for (auto it:word2)
            str2 += it; 
        return (str1 == str2);
    }
};