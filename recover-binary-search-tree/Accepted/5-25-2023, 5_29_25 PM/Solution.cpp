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
    TreeNode* node1; TreeNode* node2; TreeNode* prev;
    void rt(TreeNode* root) {
        if (!root) return;
        rt(root->left);
        if (prev && prev->val > root->val) {
            if (!node1) {
                node1 = prev;
                node2 = root;
            } else
                node2 = root;
        }
        prev = root;
        rt(root->right);
    }
    void recoverTree(TreeNode* root) {
        node1 = NULL;
        node2 = NULL;
        prev = NULL;
        rt(root);
        swap(node1->val, node2->val);
    }
};