// https://leetcode.com/problems/binary-tree-paths/description/

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
    void helper(TreeNode* root, string str, vector<string> &res) {
        if (!root) return;
        if (!root->left && !root->right) {
            str += to_string(root->val);
            res.push_back(str);
            return;
        }
        str += to_string(root->val);
        str += "->";
        helper(root->left, str, res);
        helper(root->right, str, res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        helper(root, "", res);
        return res;
    }
};