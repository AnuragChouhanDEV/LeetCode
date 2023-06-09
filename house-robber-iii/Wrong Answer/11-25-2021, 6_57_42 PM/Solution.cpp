// https://leetcode.com/problems/house-robber-iii

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
    int rob(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int odd_sum = 0;
        int even_sum = 0;
        bool odd = 1;
        while (!q.empty()) {
            for (int node_count = q.size(); node_count; --node_count) {
                TreeNode *node = q.front();
                if (odd) {
                    odd_sum += node->val;
                } else {
                    even_sum += node->val;
                }
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            odd = !odd;
        }
        return max(odd_sum, even_sum);
    }
};