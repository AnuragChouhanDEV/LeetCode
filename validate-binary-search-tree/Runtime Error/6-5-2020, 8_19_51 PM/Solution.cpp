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
    bool validate(TreeNode* root, double min, double max) {
        if (!root)
            return true;
        if (root->val >= max || root->val <= min)
            return false;
        else
            return validate(root->left, min, (double)root->val) && validate(root->right, (double)root->val, max);;
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, INT_MIN+1, INT_MAX+1);
    }
};