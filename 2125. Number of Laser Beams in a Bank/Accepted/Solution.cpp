// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/?envType=daily-question&envId=2024-01-03

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0;
        int prev_cnt = 0;
        for (int i = bank.size()-1; i >= 0; --i) {
            int curr_cnt = 0;
            for (auto c:bank[i]) {
                if (c == '1')
                    curr_cnt++;
            }
            res += prev_cnt*curr_cnt;
            if (curr_cnt)
                prev_cnt=curr_cnt;
        }
        return res;
    }
};