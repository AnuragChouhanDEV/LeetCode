// https://leetcode.com/problems/maximum-total-importance-of-roads/description/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        vector<pair<int,int>> size(n,{0,0});
        unordered_map<int, int> ma;
        long long res = 0;
        for (auto it:roads) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            size[it[0]].first++;
            size[it[1]].first++;
        }
        for (int i = 0; i < n;++i)
            size[i].second = i;
        sort(size.rbegin(), size.rend());
        int rank = n;
        for (int i = 0; i < n;++i) {
            //cout << "{" << size[i].first << ", "<<size[i].second<<"} ";
            ma[size[i].second] = rank--;
        }
        for (auto it:roads) {
            res += ma[it[0]] + ma[it[1]];
        }
        return res;
    }
};

/*
0 -> 1 2(2)         3
1 -> 0 2 3(3)       4
2 -> 1 3 0 4(4)     5
3 -> 2 1(3)         2
4 -> 2(1)           1

idx/size
0 1 2 3 4
2 3 4 2 1

sorted size
2 1 0 3 4
4 3 2 2 1

rank
0 1 2 3 4
3 4 5 2 1
7+9+7+8+6+6= 


0 -> 3              4
1 -> 3              3
2 -> 4              2
3 -> 0 1            5
4 -> 2              1


*/