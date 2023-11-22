// https://leetcode.com/problems/diagonal-traverse-ii/description/?envType=daily-question&envId=2023-11-22

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<int> res;

        while(!q.empty()) {
            int size = q.size();
            
            while (size--) {
                pair<int,int> p = q.front();
                int i = p.first;
                int j = p.second;
                q.pop();

                res.push_back(nums[i][j]);

                if (i+1 < nums.size() && j == 0)
                    q.push({i+1, j});

                if (i < nums.size() && j+1 < nums[i].size())
                    q.push({i, j+1});
            }
        }
        return res;
    }
};

/*
00
10 01
20 11 02
30 21 12 03
40 31 22 13 04
*/