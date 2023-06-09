// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        unordered_map<char, int> ma;
        int count = 1;
        int left = 0;
        int right = 1;
        ma[s[left]] = left;
        while (right < s.size()) {
            if (ma.find(s[right]) != ma.end())
                //left = max(left, ma[s[right]]+1);
                left = ma[s[right]]+1;
            count = max(count, right-left+1);
            ma[s[right]]=right;
            right++;
        }
        return count;
    }
};