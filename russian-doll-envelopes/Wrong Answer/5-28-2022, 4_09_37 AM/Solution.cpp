// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int row = envelopes.size();
        int col = envelopes[0].size();
        int count = 1;
        sort(envelopes.begin(), envelopes.end());
        int j = 0;
        for (int i = 1; i < row; ++i) {
            if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                count++;
                j++;
            } else if (envelopes[i][0] == envelopes[j][0] && envelopes[i][1] == envelopes[j][1]) {
                j++;
            }
        }
        return count;
    }
};