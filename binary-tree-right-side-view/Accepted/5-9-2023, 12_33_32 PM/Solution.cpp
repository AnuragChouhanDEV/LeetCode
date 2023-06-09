// https://leetcode.com/problems/binary-tree-right-side-view

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
    void helper(TreeNode* root, vector<int> &res, int height) {
        if (!root)
            return;
        if (height > res.size())
            res.push_back(root->val);
        helper(root->right, res, height+1);
        helper(root->left, res, height+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(root, res, 1);
        return res;
    }
};