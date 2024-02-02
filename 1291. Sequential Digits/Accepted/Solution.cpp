// https://leetcode.com/problems/sequential-digits/description/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int i = 1; i < 10; ++i) {
            int val = i;
            int j = i+1;
            while (val <= high && j < 10) {
                val = (val*10)+j;
                if (val >= low && val <= high)
                    res.push_back(val);
                ++j;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};