// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/?envType=daily-question&envId=2023-11-20

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<int, int> last;
        int ans = 0;
        for (int i = 0; i < garbage.size(); ++i) {
            ans += garbage[i].size();
            for (auto c: garbage[i])
                last[c] = i;
        }
        for (int i = 1; i < travel.size(); ++i)
            travel[i] += travel[i-1];

        for (auto c: "MPG") {
            if (last[c])
                ans += travel[last[c]-1];
        }
        return ans;
    }
};

/*
Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
Output: 21

map_last
G 2
P 3
M 

ans += 1 1 2 2 = 6

travel [2 6 9]

ans += 6 9
M 
P
G

*/