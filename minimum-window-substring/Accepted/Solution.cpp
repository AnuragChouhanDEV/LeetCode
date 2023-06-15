// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;  // map of character frequencies in t
        for (char c : t) {
            tMap[c]++;
        }
        int left = 0;
        int right = 0;
        int tCount = tMap.size();
        int minLength = INT_MAX;
        int minStart = -1;
        unordered_map<char, int> sMap;  // map of character frequencies in current window
        while (right < s.size()) {
            char c = s[right];
            sMap[c]++;
            if (tMap.count(c) > 0 && tMap[c] == sMap[c]) {
                tCount--;
            }
            while (tCount == 0) {  // found a window with all characters in t
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minStart = left;
                }
                char d = s[left];
                sMap[d]--;
                if (tMap.count(d) > 0 && tMap[d] > sMap[d]) {
                    tCount++;
                }
                left++;
            }
            right++;
        }
        return (minStart == -1) ? "" : s.substr(minStart, minLength);
    }
};