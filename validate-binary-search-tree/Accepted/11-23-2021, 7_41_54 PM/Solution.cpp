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
#if 0   
    void inorder(TreeNode *root, queue<int> &q) {
        if (!root)
            return;
        inorder(root->left, q);
        q.push(root->val);
        inorder(root->right, q);
    } 
#endif
    void inorder(TreeNode *root, queue<int> &q)
    {
        stack<TreeNode *> s;
        TreeNode *curr = root;
        while (curr != NULL || s.empty() == false)
        {
            while (curr !=  NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            q.push(curr->val);
            curr = curr->right;
        }
    }
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        queue<int> q;
        inorder(root, q);
        int node = q.front();
        q.pop();
        while(!q.empty()) {
            if (node >= q.front())
                return false;
            node = q.front();
            q.pop();
        }
        return true;
    }
};