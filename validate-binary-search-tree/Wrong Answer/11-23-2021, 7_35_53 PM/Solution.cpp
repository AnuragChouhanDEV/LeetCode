// https://leetcode.com/problems/validate-binary-search-tree

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
    void inorder(TreeNode *root, queue<int> &q) {
        if (!root)
            return;
        inorder(root->left, q);
        q.push(root->val);
        inorder(root->right, q);
    } 
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        queue<int> q;
        inorder(root, q);
        int node = q.front();
        q.pop();
        while(!q.empty()) {
            if (node > q.front())
                return false;
            node = q.front();
            q.pop();
        }
        return true;
    }
};