// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int size = trust.size();
        map<int,int> m;
        
        for (int i = 0; i < size; ++i) {
            m[trust[i][1]]++;
        }
        for (auto i : m) {
            if (i.second == (N-1))
                return i.first;
        }
        return -1;
    }
};