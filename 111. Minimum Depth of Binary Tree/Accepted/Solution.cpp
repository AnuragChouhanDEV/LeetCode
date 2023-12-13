// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

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
    int ht = INT_MAX;
    void helper(TreeNode* root, int lvl) {
        if (!root) return;
        if (!root->left && !root->right) {
            ht = min(ht, lvl);
            return;
        }
        helper(root->left, lvl+1);
        helper(root->right, lvl+1);
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        helper(root, 1);
        return ht;
    }
};