// https://leetcode.com/problems/count-complete-tree-nodes

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
    int counter(TreeNode *root) {
        if (!root)
            return 0;
        int ll = 1;
        TreeNode *l = root->left;
        while (l) {
            ll++;
            l = l->left;
        }
        int rl = 1;
        TreeNode *r = root->right;
        while (r) {
            rl++;
            r = r->right;
        }
        if (ll == rl) {
            //cout << 
            return (1 << ll)-1;
        }
        
        return (1 + counter(root->left) + counter(root->right));
    }
    int countNodes(TreeNode* root) {
        return counter(root);
#if 0
        int count = 0;
        if (!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            if (node)
                count++;
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        return count;
#endif
    }
};