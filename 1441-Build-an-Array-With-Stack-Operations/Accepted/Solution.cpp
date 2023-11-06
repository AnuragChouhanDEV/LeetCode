// https://leetcode.com/problems/build-an-array-with-stack-operations/description/?envType=daily-question&envId=2023-11-03

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        for (int i = 1,j = 0; i <= n && j < target.size(); ++i) {
            if (i == target[j]) {
                result.push_back("Push");
                j++;
            } else {
                result.push_back("Push");
                result.push_back("Pop");
            }
        }
        return result;
    }
};