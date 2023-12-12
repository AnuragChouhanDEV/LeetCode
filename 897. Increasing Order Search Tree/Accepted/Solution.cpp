// https://leetcode.com/problems/increasing-order-search-tree/description/

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
    TreeNode *dummy;
    void helper(TreeNode* root) {
        if (!root) return;
        helper(root->left);
        root->left = NULL;
        dummy->right = root;
        dummy = root;
        helper(root->right); 
    }
    TreeNode* increasingBST(TreeNode* root) {
       dummy = new TreeNode(0);
       TreeNode *dummy1 = dummy;
       helper(root);
       return dummy1->right; 
    }
};