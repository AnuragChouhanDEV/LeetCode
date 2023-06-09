// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s1 = "";
        string s2 = "";
        
        int i = 0;
        while(S[i] != '\0') {
            if(S[i]>='a' && S[i]<='z')
                s1 += S[i];
            else if (!s1.empty())
                s1.pop_back();
            ++i;
                
        }
        i = 0;
        while(T[i] != '\0') {
            if(T[i]>='a' && T[i]<='z')
                s2 += T[i];
            else if (!s2.empty())
                s2.pop_back();
            ++i;
        }
        if(s1.compare(s2) == 0)
            return true;
        return false;
    }

};