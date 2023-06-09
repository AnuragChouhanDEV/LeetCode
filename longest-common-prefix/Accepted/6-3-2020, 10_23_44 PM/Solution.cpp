// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = "";
        if (strs.size() == 0)
            return lcp;
        int idx = 0;
        for (auto c:strs[0]) {
            for (int i = 1; i < strs.size();++i) {
                if(idx >= strs[i].size() || c != strs[i][idx])
                    return lcp;
            }
            
            lcp += c;
            idx++;
        }
        //cout << lcp << endl;
        return lcp;
    }
};