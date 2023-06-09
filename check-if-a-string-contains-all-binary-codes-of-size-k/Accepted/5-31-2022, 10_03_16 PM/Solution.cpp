// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> ss;
        int start = 0;
        if (s.size() < k)
            return false;
        while (start < s.size()-k+1) {
            ss.insert(s.substr(start, k));
            //cout << s.substr(start, k) << " " << pow(2,k) << " "<< ss.size()<<endl;
            if (ss.size() == (pow(2,k)))
                return true;
            start++;
        }      
        if (ss.size() == pow(2,k))
            return true;
        return false;
    }
};