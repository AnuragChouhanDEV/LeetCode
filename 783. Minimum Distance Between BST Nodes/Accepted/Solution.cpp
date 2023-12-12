// https://leetcode.com/problems/minimum-distance-between-bst-nodes/

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
    int ans = INT_MIN+100000;
    int min_diff = INT_MAX;
    int minDiffInBST(TreeNode* root) {
        if (!root) return 0;
        minDiffInBST(root->left);
        min_diff = min(min_diff, root->val - ans);
        ans = root->val;
        minDiffInBST(root->right);
        return min_diff;
    }
};