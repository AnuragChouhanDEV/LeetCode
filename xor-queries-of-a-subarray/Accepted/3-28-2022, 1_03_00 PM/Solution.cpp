// https://leetcode.com/problems/xor-queries-of-a-subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        //int pre[arr.size()];
        //pre[0] = arr[0];
        for (int i = 1; i < arr.size(); ++i)
            arr[i] = arr[i]^arr[i-1];
        for (auto q:queries) {
            int left = q[0];
            int right = q[1];
            if (left == 0)
                res.push_back(arr[right]);
            else
                res.push_back(arr[right]^arr[left-1]);
        }
        return res;
    }
};