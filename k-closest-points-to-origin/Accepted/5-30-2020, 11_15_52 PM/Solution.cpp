// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int len = points.size();
        vector<pair<int,pair<int,int>>> vec;
        for (int i = 0; i < len; ++i) {
            vec.push_back(make_pair(points[i][0]*points[i][0] + points[i][1]*points[i][1],make_pair(points[i][0],points[i][1])));
        }
        sort(vec.begin(),vec.end());
        vector<vector<int>> ans(K);
        for (int i = 0; i < K; ++i) {
            ans[i].push_back(vec[i].second.first);
            ans[i].push_back(vec[i].second.second);
        }
        return ans;
    }
};