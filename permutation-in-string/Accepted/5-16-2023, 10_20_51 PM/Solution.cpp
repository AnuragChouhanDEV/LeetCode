// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_hash(26,0);
        vector<int> s2_hash(26,0);
        int left = 0;
        int right = 0;
        if (s1.size() > s2.size())
            return false;
        for (;right < s1.size(); ++right) {
            s1_hash[s1[right]-'a']++;
            s2_hash[s2[right]-'a']++;
        }
        right--;
        while (right < s2.size()) {
            if (s1_hash == s2_hash)
                return true;
            right++;
            if (right != s2.size())
                s2_hash[s2[right]-'a']++;
            s2_hash[s2[left]-'a']--;
            left++;
        }
        return false;
    }
};