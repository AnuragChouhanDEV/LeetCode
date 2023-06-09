// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int greatest = 0;
        vector<bool> res;
        for (auto a:candies) greatest = max(greatest, a);
        for (auto a:candies) {
            if (a+extraCandies >= greatest)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};