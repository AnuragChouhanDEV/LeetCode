// https://leetcode.com/problems/minimum-absolute-difference-in-bst

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
    int mini = 100001;
    void gmd(TreeNode* root, TreeNode* &prev) {
        if (!root) return;
        gmd(root->left, prev);
        if (prev) {
            mini = min(mini, abs(prev->val - root->val));
        }
        prev = root;
        gmd(root->right, prev);
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev = NULL;
        gmd(root, prev);
        return mini;
    }
};