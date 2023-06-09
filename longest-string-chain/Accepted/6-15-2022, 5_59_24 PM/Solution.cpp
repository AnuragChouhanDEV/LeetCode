// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    static bool length_sort(string a, string b) {
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> ma;
        int ans = 0;
        sort(words.begin(), words.end(), length_sort);
        for (auto word:words) {
            for (int i = 0; i < word.size(); ++i) {
                string new_str = word.substr(0,i)+word.substr(i+1);
                ma[word] = max(ma[word], ma[new_str]+1);
            }
            ans = max(ans, ma[word]);
        }
        return ans;
    }
};