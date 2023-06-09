// https://leetcode.com/problems/balanced-binary-tree

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
    int helper(TreeNode* root) {
        if (!root)
            return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        int diff = abs(left-right);
        if (diff > 1 || left == -1 || right == -1)
            return -1;
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        return helper(root) != -1;
    }
};