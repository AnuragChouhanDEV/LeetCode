// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> phash(26,0);
        vector<int> hash(26,0);
        int window = p.size();
        int len = s.size();
        int left = 0;
        int right = 0;
        if (len < window)
            return ans;
        while (right < window) {
            phash[p[right] - 'a'] += 1;
            hash[s[right] - 'a'] += 1;
            right++;
        }
        right--;
        while (right < len) {
            if (phash == hash)
                ans.push_back(left);
            right++;
            if (right != len) {
                hash[s[right] - 'a'] += 1;
            }
            hash[s[left] - 'a'] -= 1;
            left++;
        }
        return ans;
    }
};