// https://leetcode.com/problems/path-sum-ii

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void path_sum(TreeNode *root, int targetSum, vector<int> &vec, vector<vector<int>> &res) {
        if (!root)
            return;
        int sum = targetSum - root->val;
        vec.push_back(root->val);
        if (root->left)
            path_sum(root->left, sum, vec, res);
        if (root->right)
            path_sum(root->right, sum, vec, res);
        if (sum == 0 && !root->left && !root->right) {
            res.push_back(vec);
        }
        vec.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> vec;
        vector<vector<int>> res;
        path_sum(root, targetSum, vec, res);
        return res;
    }
};