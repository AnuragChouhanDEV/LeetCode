// https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2023-12-22

class Solution {
public:
    int maxScore(string s) {
        int max_score = 0;
        int count_zeros_left = 0;
        int count_ones_right = std::count(s.begin(), s.end(), '1');

        for (int i = 0; i < s.size() - 1; ++i) {
            count_zeros_left += (s[i] == '0');
            count_ones_right -= (s[i] == '1');
            max_score = std::max(max_score, count_zeros_left + count_ones_right);
        }

        return max_score;
    }
};

/*
1 1 1 1 2 2
4 4 3 2 1 1

1 2 2 2 2
3 3 3 2 1

0 0 0 0
4 3 2 1

*/