// https://leetcode.com/problems/stone-game-iii

class Solution {
public:
    int helper(vector<int>& stoneValue, int idx, int size, vector<int> &res) {
        if (idx >= size) return 0;
        if (res[idx] != -1) return res[idx];
        int one = stoneValue[idx] - helper(stoneValue, idx+1, size, res);
        int two = (idx+1 < size) ? stoneValue[idx] + stoneValue[idx+1] - helper(stoneValue, idx+2, size, res):INT_MIN;
        int three = (idx+2 < size) ? stoneValue[idx] + stoneValue[idx+1] + stoneValue[idx+2] - helper(stoneValue, idx+3, size, res):INT_MIN;
        return res[idx]=max(one,max(two,three));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> res(stoneValue.size()+1, -1);
        int diff_score = helper(stoneValue, 0, stoneValue.size(), res);
        if (diff_score > 0) return "Alice";
        else if (diff_score < 0) return "Bob";
        else return "Tie";
    }
};