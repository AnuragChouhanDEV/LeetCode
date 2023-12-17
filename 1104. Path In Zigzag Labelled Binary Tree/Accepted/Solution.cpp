// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/description/

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> r;
        r.push_back(label);
        int d=log2(label),m;
        while(d)
        {
            m=(1 << d)+(1 << (d+1))-1-label;  
            r.push_back(m/2);
            label=m/2;
            d--;
        }
        reverse(r.begin(),r.end());
        return r;
    }
};

/*
2^0 = 1
2^1 = 2     1
2^2 = 4     3       3       2
2^3 = 8     7       45      67
2^4 = 16    15      12131415        891011


8 + 1

1110
*/