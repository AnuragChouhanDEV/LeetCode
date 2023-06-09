// https://leetcode.com/problems/count-good-nodes-in-binary-tree

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
    TreeNode *prev;
    int count = 0;
    void cgn(TreeNode* root, int &max) {
        if (!root) return;
        if (root->val >= max) {
            count++;
            max = root->val;
        }
        cgn(root->left, max);
        cgn(root->right, max);
    }
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int max = root->val;
        cgn(root, max);
        return count;
    }
};