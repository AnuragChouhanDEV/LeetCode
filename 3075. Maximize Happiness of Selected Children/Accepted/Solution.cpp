// https://leetcode.com/problems/maximize-happiness-of-selected-children/description/

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        sort(happiness.begin(), happiness.end());
        long long res = happiness[happiness.size()-1];
        int hp = 1;
        for(int i = happiness.size()-2; i >= 0 && hp < k; i--,hp++) res += max(happiness[i] - hp, 0);
        return res;
    }
};

/*
1   12  42

*/