// https://leetcode.com/problems/stone-game-iii

class Solution {
public:



    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> res(stoneValue.size()+1, 0);
        int n = stoneValue.size();

        for (int i = n-1; i >= 0; --i) {
            int one = stoneValue[i] - res[i+1];
            int two = (i+1 < n) ? stoneValue[i] + stoneValue[i+1] - res[i+2] : INT_MIN;
            int three = (i+2 < n) ? stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - res[i+3] : INT_MIN;
            res[i]=max(one,max(two,three));
        }

        if (res[0] > 0) return "Alice";
        else if (res[0] < 0) return "Bob";
        else return "Tie";
    }


#if 0
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
#endif
};