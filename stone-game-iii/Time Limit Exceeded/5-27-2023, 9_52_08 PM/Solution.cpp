// https://leetcode.com/problems/stone-game-iii

class Solution {
public:
    int helper(vector<int>& stoneValue, int idx, int size) {
        if (idx >= size) return 0;
        int one = stoneValue[idx] - helper(stoneValue, idx+1, size);
        int two = (idx+1 < size) ? stoneValue[idx] + stoneValue[idx+1] - helper(stoneValue, idx+2, size):INT_MIN;
        int three = (idx+2 < size) ? stoneValue[idx] + stoneValue[idx+1] + stoneValue[idx+2] - helper(stoneValue, idx+3, size):INT_MIN;
        return max(one,max(two,three));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int diff_score = helper(stoneValue, 0, stoneValue.size());
        if (diff_score > 0) return "Alice";
        else if (diff_score < 0) return "Bob";
        else return "Tie";
    }
};