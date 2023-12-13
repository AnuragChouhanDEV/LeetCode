// https://leetcode.com/problems/subtree-of-another-tree/description/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (p && !q || !p && q)
            return false;
        return (p->val == q->val && (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right)));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        
        bool flag = isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        if (root->val == subRoot->val)
            return flag || isSameTree(root, subRoot);
        return flag;
    }
};