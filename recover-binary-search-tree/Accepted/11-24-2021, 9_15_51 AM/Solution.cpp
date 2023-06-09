// https://leetcode.com/problems/recover-binary-search-tree

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
    void recoverTreeUtil(TreeNode *root, TreeNode **first, TreeNode **middle, TreeNode **last, TreeNode **prev) {
        if (!root)
            return;
        recoverTreeUtil(root->left, first, middle, last, prev);
        if (*prev && (*prev)->val > root->val) {
            if (!*first) {
                *first = *prev;
                *middle = root;
            } else
                *last = root;
        }
        *prev = root;
        recoverTreeUtil(root->right, first, middle, last, prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL;
        TreeNode *middle = NULL;
        TreeNode *last = NULL;
        TreeNode *prev = NULL;
        recoverTreeUtil(root, &first, &middle, &last, &prev);
        if (first && last)
            swap((first->val), (last->val));
        else if (first && middle)
            swap((first->val), (middle->val));
    }
};