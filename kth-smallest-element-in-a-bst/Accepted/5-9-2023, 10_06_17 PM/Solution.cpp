// https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
    void _kthSmallest(TreeNode* root, int k, int &count, int &res) {
        if (!root)
            return;
        _kthSmallest(root->left, k, count, res);
        count++;
        if (count == k)
            res = root->val;
        if (res)
            return;
        _kthSmallest(root->right, k, count, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        int count = 0;
        _kthSmallest(root, k, count, res);
        return res;
    }
};