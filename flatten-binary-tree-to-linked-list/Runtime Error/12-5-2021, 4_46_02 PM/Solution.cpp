// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    void flatten(TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return;
        if (root->left) {
            flatten(root->left);
            //cout << root->val << " ";
            TreeNode *right = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode *tmp = root->right;
            while(tmp && tmp->right && tmp->right->val < right->val) {
                tmp = tmp->right;
            }
            TreeNode *t = tmp->right;
            tmp->right = right;
            while (right && right->right)
                right = right->right;
            if (right)
                right->right = t;
        }
        flatten(root->right);
    }
};