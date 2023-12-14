// https://leetcode.com/problems/balance-a-binary-search-tree/description/

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
    TreeNode* build_bst(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;
        int idx = (l+r)/2;
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = build_bst(nums, l, idx-1);
        root->right = build_bst(nums, idx+1, r);
        return root;
    }
    void get_vec(TreeNode* root, vector<int> &v) {
        if (!root) return;
        get_vec(root->left, v);
        v.push_back(root->val);
        get_vec(root->right, v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        get_vec(root, v);
        TreeNode* node = build_bst(v, 0, v.size()-1);
        return node;
    }
};