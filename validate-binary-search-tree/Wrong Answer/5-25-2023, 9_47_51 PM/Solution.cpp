// https://leetcode.com/problems/validate-binary-search-tree

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
    bool helper(TreeNode* root, long long left, long long right) {
        if (!root) return true;
        if (root->val >= (int)right || root->val <= (int)left) return false;
        return helper(root->left, left, (long long)root->val) && helper(root->right, (long long)root->val, right);
    }
    bool isValidBST(TreeNode* root) {
        if (!root->left && !root->right)
            return true;
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};