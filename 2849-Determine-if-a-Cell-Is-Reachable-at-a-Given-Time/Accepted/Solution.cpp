// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/?envType=daily-question&envId=2023-11-08

class Solution {
public:
    
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xd = abs(fx-sx);
        int yd = abs(fy-sy);
        if (xd == 0 && yd == 0 && t == 1)
            return false;
        return ((min(xd,yd) + abs(xd-yd)) <= t);
    }
};