// https://leetcode.com/problems/leaf-similar-trees

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
    void get_leaf_inorder(TreeNode* root, vector<int> &res) {
        if (!root) return;

        get_leaf_inorder(root->left, res);
        if (!root->left && !root->right) {
            res.push_back(root->val);
            return;
        }
        get_leaf_inorder(root->right, res);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        vector<int> res2;
        get_leaf_inorder(root1, res1);
        get_leaf_inorder(root2, res2);
        return res1==res2;
    }
};