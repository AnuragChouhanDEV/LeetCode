// https://leetcode.com/problems/diameter-of-binary-tree/description/

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
    int res = 0;
    int helper (TreeNode *root) {
        if (!root) 
            return -1;
        if (!root->left && !root->right)
            return 0;
        int left = 1+helper(root->left);
        int right = 1+helper(root->right);
        res = max(res, left+right);
        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return res;
    }
};