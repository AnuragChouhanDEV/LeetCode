// https://leetcode.com/problems/cousins-in-binary-tree/description/

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
    int lvlx = 0;
    int lvly = 0;
    TreeNode *px;
    TreeNode *py;
    void helper(TreeNode *root, int el, int lvl) {
        if (!root) return;
        if (root->left && root->left->val == el)
            px = root;
        if (root->right && root->right->val == el)
            px = root;
        if (root->val == el)
            lvlx = lvl;
        helper(root->left, el, lvl+1);
        helper(root->right, el, lvl+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        helper(root, y, 0);
        lvly = lvlx;
        py = px;
        helper(root, x, 0);
        cout << lvlx << " "<<lvly<<endl;
        return lvlx == lvly && px != py;
    }
};