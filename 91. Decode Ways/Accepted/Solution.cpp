// https://leetcode.com/problems/decode-ways/description/?envType=daily-question&envId=2023-12-25

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();        
        if (n == 0 || s[0] == '0') return 0;      
        vector<int> vec(n+1, 0);
        vec[0]=1;
        vec[1]=1;
        for (int i = 2; i <= n; ++i) {
            int d1 = s[i-1]-'0';
            int d2 = stoi(s.substr(i-2,2));
            if (d1 != 0)
                vec[i] += vec[i-1];
            if (d2 >= 10 && d2 <= 26) {
                vec[i] += vec[i-2];
            }
        }
        return vec[n];
    }
};

/*
1 2 3 4 .. 10 11 12 13 .. 20 21 22 .. 26
22206
1135
 

*/