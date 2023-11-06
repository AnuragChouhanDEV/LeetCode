// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/?envType=daily-question&envId=2023-11-04

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lmax = 0;
        int rmin = 0;
        if (left.size()) {
            lmax = left[0];
            for (int i = 1; i < left.size(); ++i)
                lmax = max(lmax, left[i]);
        }
        if (right.size()) {
            rmin = right[0];
            for (int i = 1; i < right.size(); ++i)
                rmin = min(rmin, right[i]);
        }

        if (left.size() && right.size())
            return max(lmax, n-rmin);
        else if (left.size())
            return lmax;
        else
            return n-rmin;
    }
};