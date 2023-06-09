// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        if (num == 0)
            return ans;
        if (num >= 0) {
            ans[0] = 0;
            ans[1] = 1;
        }
        for (int i = 2; i <= num; ++ i) {
            if (i&1)
                ans[i] = ans[i/2]+1;
            else
                ans[i] = ans[i/2];
        }
        return ans;
    }
};