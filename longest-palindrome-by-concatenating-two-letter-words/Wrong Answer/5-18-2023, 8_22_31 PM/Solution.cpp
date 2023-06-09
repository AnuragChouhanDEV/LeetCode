// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> visited(26, vector<int>(26,0));
        int res = 0;
        for (string s:words) {
            int x = s[0]-'a';
            int y = s[1]-'a';
            if (visited[y][x] == 1) {
                res+=4;
                visited[y][x]--;
            } else
                visited[x][y]++;
        }
        for (int i = 0; i < 26; ++i)
            if (visited[i][i]) {
                res+=2;
                break;
            }
        return res;
    }
};