// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/?envType=daily-question&envId=2023-12-05

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> ma;
        vector<vector<int>> res;
        for (int i = 0; i < groupSizes.size(); ++i) {
            ma[groupSizes[i]].push_back(i);
        }
        for (auto it = ma.begin(); it != ma.end(); ++it) {
            if (it->second.size() < it->first)
                res.push_back(it->second);
            else {
                int j = 0;
                vector<int> v;
                for (auto i:it->second) {
                    if (j < it->first) {
                        v.push_back(i);
                        ++j;
                    }
                    if (j == it->first) {
                        j = 0;
                        res.push_back(v);
                        v.clear();
                        //v.push_back(i);
                    }
                }
                if (v.size())
                    res.push_back(v);
            }
        }
        return res;
    }
};