// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int count = 0;
        vector<int> res;
        for (int i = 0; i < dist.size(); ++i) {
            res.push_back(ceil((double)dist[i]/(double)speed[i]));
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); ++i) {
            if (i >= res[i])
                return count;
            count++;
        }
        return count;
    }
};