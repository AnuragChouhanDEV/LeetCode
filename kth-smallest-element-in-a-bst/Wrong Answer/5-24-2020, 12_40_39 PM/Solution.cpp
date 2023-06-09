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
    int in_order(TreeNode *root, int k) {
        if (root == NULL)
            return 0;
        int left = in_order(root->left, k);
        if (left)
            return left;
        k--;
        if (!k)
            return root->val;
        int right = in_order(root->right, k);
        return right;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return in_order(root, k);
    }
};