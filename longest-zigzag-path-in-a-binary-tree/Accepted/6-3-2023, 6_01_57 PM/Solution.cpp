// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

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
    int maxi = 0;
    void _lzz(TreeNode* root, bool left, int len) {
        if (!root) return;
        maxi = max(maxi, len);
        _lzz(root->left, 0, left ? len + 1 : 1);
        _lzz(root->right, 1, left ? 1 : len + 1);
    }
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        bool dir = true;
        
        _lzz(root, 0, 0);
        _lzz(root, 1, 0);
        return maxi;
    }
};