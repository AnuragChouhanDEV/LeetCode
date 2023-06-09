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
    bool validate(TreeNode* root, int min, int max) {
        if (!root)
            return true;
        else if ((max != 0 && root->val >= max) || (min != 0 && root->val <= min))
            return false;
        else
            return validate(root, min, root->val) && validate(root, root->val, max);;
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, 0, 0);
    }
};