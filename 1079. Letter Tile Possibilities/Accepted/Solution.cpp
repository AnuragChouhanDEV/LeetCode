// https://leetcode.com/problems/letter-tile-possibilities/description/

class Solution {
public:
    int res = -1;
    void helper(string tiles, int idx) {
        res++;
        for (int i = idx; i < tiles.size(); ++i) {
            if (i != idx && tiles[i] == tiles[idx]) continue;
            swap(tiles[i], tiles[idx]);
            helper(tiles, idx+1);
        }
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        int i = 0;
        helper(tiles,i);
        return res;
    }
};