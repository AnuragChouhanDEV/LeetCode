// https://leetcode.com/problems/maximal-network-rank/description/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> count(n);
        vector<vector<int>> links(n, vector<int>(n, 0));

        for (auto road:roads) {
            count[road[0]]++;count[road[1]]++;
            links[road[0]][road[1]] = 1;
            links[road[1]][road[0]] = 1;
        }
        int rank = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                rank = max(rank, count[i] + count[j] - links[i][j]);
            }
        }
        return rank;
    }
};

/*
0 -> 1 3
1 -> 0 2 3
2 -> 1
3 -> 0 1

1 1 1 1

0 -> 1 3
1 -> 0 2 3
2 -> 1 3 4
3 -> 0 1 2
4 ->2

1 1 1 1 1

0 -> 1
1 -> 0 2
2 -> 1 3 4
3 -> 2
4 -> 2
5 -> 6 7
6 -> 5
5 -> 5

1 1 1 1 1 0 0 0
*/