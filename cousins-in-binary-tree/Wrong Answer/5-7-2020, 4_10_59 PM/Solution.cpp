// https://leetcode.com/problems/cousins-in-binary-tree

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
    bool sibling(TreeNode* root, int x, int y) {
        if (root == NULL)
            return false;
        if (root->left == NULL || root->right == NULL)
            return 0;
        return ((root->left->val == x && root->right->val == y) ||
                (root->left->val == y && root->right->val == x) ||
                sibling(root->left, x, y) || sibling(root->right, x, y));
    }
    int level(TreeNode* root, int x, int lev) {
        if (root == NULL)
            return 0;
        
        if (root->val == x)
            return lev;
        
        int l = level(root->left, x, lev+1);
        if (l != 0)
            return l;
        return level(root->right, x, lev+1);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL)
            return 0;

        
        if (level(root, x, 1) == level(root, y, 1) && sibling(root, x, y)) {
            return 1;
        }
        return 0;
    }
};