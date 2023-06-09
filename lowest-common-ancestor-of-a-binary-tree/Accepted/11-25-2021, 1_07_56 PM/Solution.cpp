// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool find_path(TreeNode* root, int target, vector<TreeNode *> &path) {
        if (!root)
            return false;
        path.push_back(root);
        if (target == root->val)
            return true;
        if (find_path(root->left, target, path) || find_path(root->right, target, path))
            return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> p1, p2;
        if (!find_path(root, p->val, p1) || !find_path(root, q->val, p2))
            return NULL;
        int i;
#if 1
        for (i = 0; i < p1.size() && i < p2.size(); ++i)
            if (p1[i] != p2[i])
                break;
#endif
        return p1[i-1];
    }
};