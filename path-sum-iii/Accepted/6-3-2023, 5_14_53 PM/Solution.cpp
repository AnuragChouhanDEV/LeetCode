// https://leetcode.com/problems/path-sum-iii

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
    typedef long long ll;
    int _pathSum(TreeNode* root, ll targetSum) {
        if (!root) return 0;
        int res = 0;
        if (root->val == targetSum) res++;
        res += _pathSum(root->left, (ll)targetSum - (ll)root->val);
        res += _pathSum(root->right, (ll)targetSum - (ll)root->val);
        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + _pathSum(root, (ll)targetSum);
    }
};