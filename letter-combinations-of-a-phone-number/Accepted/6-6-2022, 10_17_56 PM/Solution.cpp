// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    void letterCombRec(vector<string> &ans, string nums[], string digits, int idx, string str) {
        if (idx == digits.size()) {
            ans.push_back(str);
            return;
        }
        string val = nums[digits[idx]-'0'];
        for (int j = 0; j < val.size(); ++j) {
            letterCombRec(ans, nums, digits, idx+1, str+val[j]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size() == 0)
            return ans;
        string nums[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        letterCombRec(ans, nums, digits, 0, "");
        return ans;
    }
};