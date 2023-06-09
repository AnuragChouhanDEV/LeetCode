// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()) {
            int size = q.size();
            vector<int> vec;
            for (int i = 0; i < size; ++i) {
                TreeNode *tmp = q.front();
                q.pop();
                if (flag) {
                    if (tmp->left) q.push(tmp->left);
                    if (tmp->right) q.push(tmp->right);
                } else {
                    if (tmp->right) q.push(tmp->right);
                    if (tmp->left) q.push(tmp->left);
                }
                vec.push_back(tmp->val);
            }
            flag = ~flag;
            res.push_back(vec);
        }
        return res;
    }
};