// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int arr[n+1];
        for (int i = 0; i <= n; ++i) {
            arr[i] = i;
        }
        for (int i = 0; i < trust.size(); i++) {
            arr[trust[i][0]] = 0;
        }
        for (int i = 0; i <= n; ++i) {
            if (arr[i])
                return arr[i];
        }
        return -1;
    }
};