// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/

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
    void helper(TreeNode* left, TreeNode* right, int lvl) {
        if (!left && !right) return;
        if (!left || !right) return;
        if (lvl & 1) {
            int val = left->val;
            left->val = right->val;
            right->val = val;
        }
        helper(left->left, right->right, lvl+1);
        helper(left->right, right->left, lvl+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return NULL;
        helper(root->left, root->right, 1);
        return root;
    }
};
/*
            0
    1                 2
0       0        0          0
1 1   1   1    2   2      2    2
*/