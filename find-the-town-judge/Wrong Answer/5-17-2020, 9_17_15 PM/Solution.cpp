// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int size = trust.size();
        map<int,int> m;
        map<int,int> m1;
        int ret = -1;
        if (size == 0)
            return -1;
        for (int i = 0; i < size; ++i) {
            m[trust[i][1]]++;
            m1[trust[i][0]]++;
            //cout << trust[i][1] <<"-->"<<m[trust[i][1]] << endl;
        }
        cout << endl;
        for (auto i : m) {
            if (i.second == (N-1)) {
                //cout << i.first << "->" << m1[i.first] <<endl;
                if (m1[i.first] > 0) {
                    return -1;
                }
                return i.first;
            }
        }
        return -1;
    }
};