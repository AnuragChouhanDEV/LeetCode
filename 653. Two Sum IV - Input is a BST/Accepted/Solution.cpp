// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

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
    unordered_set<int> ma;
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (ma.find(k-root->val) != ma.end())
            return true;
        ma.insert(root->val);
        if (findTarget(root->left, k) || findTarget(root->right, k))
            return true;
        return false;
    }
};