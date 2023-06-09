// https://leetcode.com/problems/interval-list-intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int size1 = firstList.size();
        int size2 = secondList.size();
        int one = 0;int two = 0;

        while (one<size1 && two<size2) {
            vector<int> tmp(2,0);
            if (firstList[one][0] <= secondList[two][1] && firstList[one][1] >= secondList[two][0]) {
                tmp[0] = max(firstList[one][0], secondList[two][0]);
                tmp[1] = min(firstList[one][1], secondList[two][1]);
                res.push_back(tmp);
            }
            if (firstList[one][1] < secondList[two][1]) one++;
            else two++;
        }
        return res;
    }
};