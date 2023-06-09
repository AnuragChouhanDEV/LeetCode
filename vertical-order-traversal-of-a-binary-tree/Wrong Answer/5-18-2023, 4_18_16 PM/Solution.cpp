// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
    void _verticalTraversal(TreeNode* root, map<int, vector<int>> &ma, int idx) {
        if (!root) return;
        ma[idx].push_back(root->val);
        _verticalTraversal(root->left, ma, idx-1);
        _verticalTraversal(root->right, ma, idx+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, vector<int>> ma;
        _verticalTraversal(root, ma, 0);
        for (auto it:ma) {
            sort(it.second.begin(), it.second.end());
            res.push_back(it.second);
        }
        return res;
    }
};