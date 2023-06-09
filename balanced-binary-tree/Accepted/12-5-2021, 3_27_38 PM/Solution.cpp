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
    bool is_balanced_util(TreeNode *root, int &height) {
        if (!root)
            return true;
        int lh = 0;
        int rh = 0;
        bool l = is_balanced_util(root->left, lh);
        bool r = is_balanced_util(root->right, rh);
        if (abs(lh-rh) > 1)
            return false;
        height = 1 + max(lh,rh);
        return l && r;
    }
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return is_balanced_util(root, height);        
    }
};