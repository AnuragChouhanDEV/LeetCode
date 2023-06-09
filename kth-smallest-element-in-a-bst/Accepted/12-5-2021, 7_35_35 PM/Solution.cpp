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
    TreeNode *kthSmallestUtil(TreeNode* root, int &k) {
        if (!root)
            return NULL;
        TreeNode* left = kthSmallestUtil(root->left, k);
        if (left != NULL)
            return left;
        //cout << root->val;
        k--;
        if (k == 0)
            return root;
        return kthSmallestUtil(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *node = kthSmallestUtil(root, k);
        return node ? node->val:0;
    }
};