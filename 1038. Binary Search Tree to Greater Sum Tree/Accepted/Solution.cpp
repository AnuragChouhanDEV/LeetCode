// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/

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
    void helper(TreeNode* root, int &sum) {
        if (!root) return;
        helper(root->right, sum);
        sum += root->val;
        root->val = sum;
        helper(root->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        helper(root,sum);
        return root;
    }
#if 0
    void get_sum(TreeNode* root, int &sum) {
        if (!root) return;
        sum += root->val;
        get_sum(root->left,sum);
        get_sum(root->right,sum);
    }
    void update_sum(TreeNode* root, int &sum) {
        if (!root) return;
        update_sum(root->left,sum);
        int val = root->val;
        root->val = sum;
        sum -= val;
        update_sum(root->right,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        get_sum(root,sum);
        cout << sum << endl;
        update_sum(root, sum);
        return root;
    }
#endif
};