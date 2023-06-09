// https://leetcode.com/problems/binary-tree-right-side-view

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
    void inorder(TreeNode *root, vector<int> &res, int max) {
        if (!root)
            return;
        if (max > res.size())
            res.push_back(root->val);
        inorder(root->right, res, max+1);
        inorder(root->left, res, max+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int max = 1;
        inorder(root, res, max);
        return res;
#if 0
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                 q.pop();
                if (i == 0)
                    res.push_back(node->val);
                if (node->right)
                    q.push(node->right);
                if (node->left)
                    q.push(node->left);
            }
            
        }
        return res;
#endif
    }
};