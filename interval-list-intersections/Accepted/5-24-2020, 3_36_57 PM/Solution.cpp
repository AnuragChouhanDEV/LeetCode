// https://leetcode.com/problems/interval-list-intersections

class Solution {
    int max(int a,int b) {
        return a > b ? a : b;
    }
    int min(int a, int b) {
        return a > b ? b : a;
    }
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int a = 0,b = 0;
        int a_size = A.size();
        int b_size = B.size();
        vector<int> tmp(2);
        while (a < a_size && b < b_size) {
            if (B[b][0] <= A[a][1] && A[a][0] <= B[b][1]) {
                tmp[0] = max(A[a][0], B[b][0]);
                tmp[1] = min(B[b][1], A[a][1]);
                res.push_back(tmp);
            }
            if (A[a][1] > B[b][1]) {
                b++;
            } else
                a++;
        }
        return res;
    }
};