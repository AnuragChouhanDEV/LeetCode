// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

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
    int ans = 0;
    void helper(TreeNode* root, int mx) {
        if (!root) return;
        if (root->val >= mx) ans++;
        if (root->left)
            helper(root->left, max(mx, root->val));
        if (root->right)
            helper(root->right, max(mx, root->val));
    }
    int goodNodes(TreeNode* root) {
        helper(root, root->val);
        return ans;
    }
};