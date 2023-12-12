// https://leetcode.com/problems/evaluate-boolean-binary-tree/description/

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
    bool evaluateTree(TreeNode* root) {
        if (!root->left && !root->right)
            return root->val;
        bool left = root->left ? evaluateTree(root->left) : 0;
        bool right = root->right ? evaluateTree(root->right) : 0;
        if (root->val == 2)
            return left | right;
        return left & right;
    }
};