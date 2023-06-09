// https://leetcode.com/problems/2-keys-keyboard

class Solution {
public:
    int minSteps(int n) {
        int ans=0;
        if (n == 1)
            return 0;
        if (n == 2)
            return 2;
        for (int i = 2; i<=n;) {
            //cout << i << " " << n << endl;
            if (n%i==0) {
                ans+=i;
                n=n/i;
            } else {
                ++i;
            }
        }
        if (n!=1)
            return n;
        return ans;
    }
};
