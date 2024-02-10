// https://leetcode.com/problems/palindromic-substrings/description/?envType=daily-question&envId=2024-02-10

class Solution {
public:
    int pal(int i, int j, string &s){
        while(i >= 0 && j < s.length() && s[i] == s[j]){
            i--;
            j++;
        }
        return ((j-i) >>1);
    }
    int countSubstrings(string s) {
        int res = 0;
        for(int i = s.size()-1; i >= 0 ; --i){
           int odd = pal(i, i, s);
           int even = pal(i-1, i, s);
           res += (odd + even);
        }
        return res;      
    }
};