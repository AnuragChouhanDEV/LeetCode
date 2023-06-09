// https://leetcode.com/problems/path-sum

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = targetSum - root->val;
        int ans = 0;
        if (sum == 0 && !root->left && !root->right)
            return true;
        if (root->left)
            ans = ans || hasPathSum(root->left, sum);
        if (root->right)
            ans = ans || hasPathSum(root->right, sum);
        return ans;
    }
};