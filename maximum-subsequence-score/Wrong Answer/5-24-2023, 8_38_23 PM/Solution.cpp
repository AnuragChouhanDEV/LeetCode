// https://leetcode.com/problems/maximum-subsequence-score

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> vpa;
        long long res;
        for (int i = 0 ; i < nums2.size(); ++i) {
            vpa.push_back({nums2[i], nums1[i]});
        }
        sort(vpa.begin(), vpa.end(), greater());
        int i = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        long long local_min = 0;
        long long local_sum = 0;
        for (int i = 0; i < k; ++i) {
            auto pa = vpa[i];
            pq.push(pa.second);
            local_sum += pa.second;
            local_min = pa.first;
            //cout << " pa.first " << pa.first << " pa.second " << pa.second << endl;
        }
        //cout << " local_min " << local_min << " local_sum " << local_sum << endl;
        res = (long long) local_sum * (long long)local_min;
        for (int i = k; i < vpa.size(); ++i) {
            auto pa = vpa[i];
            int tmp = pq.top();
            local_sum -= tmp;
            local_sum += pa.second;
            pq.push(pa.second);           
            local_min = pa.first;
            res = max(res, (long long)((long long)local_sum * (long long)local_min));
        }
        return res;
    }
};