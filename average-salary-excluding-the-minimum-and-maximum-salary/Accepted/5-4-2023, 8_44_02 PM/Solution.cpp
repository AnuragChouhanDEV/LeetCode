// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary

class Solution {
public:
    double average(vector<int>& salary) {
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        double result = 0;
        for (auto it:salary) {
            minimum = min(minimum, it);
            maximum = max(maximum, it);
            result += it;
        }
        result-=minimum;
        result-=maximum;
        return (double)result/(salary.size()-2);
    }
};