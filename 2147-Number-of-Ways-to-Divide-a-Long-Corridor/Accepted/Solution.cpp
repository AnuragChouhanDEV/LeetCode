// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/description/?envType=daily-question&envId=2023-11-28

class Solution {
public:
    int numberOfWays(string corridor) {
        long long ans = 1;
        int seats = 0;
        int last_seat_idx = -1;
        for (int i = 0; i < corridor.size(); ++i) {
            char c = corridor[i];
            if (c == 'P') continue;
            seats++;

            if (seats >= 3 && seats%2 == 1) {
                ans = (ans * (i - last_seat_idx)) % 1000000007;
            }
            last_seat_idx = i;
        }

        return (seats == 0 || seats%2==1) ? 0: ans;
    }
};