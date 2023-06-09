// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> ss;
        int start = 0;
        while (start < s.size()-k) {
            ss.insert(s.substr(start, start + k));
            if (ss.size() == 2^k)
                return true;
        }      
        if (ss.size() == 2^k)
            return true;
        return false;
    }
};