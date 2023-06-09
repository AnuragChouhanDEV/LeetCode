// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    vector<int> max_path_sum_util(TreeNode *root) {
        if (!root)
            return vector<int>{0, INT_MIN};
        vector<int> l_sum = max_path_sum_util(root->left);
        int l_branch = l_sum[0];
        int l_path = l_sum[1];
        vector<int> r_sum = max_path_sum_util(root->right);
        int r_branch = r_sum[0];
        int r_path = r_sum[1];
        
        int max_of_l_r = max(r_branch, l_branch);
        int max_branch = max(root->val, max_of_l_r + root->val);
        int max_sum_root = max(max_branch, l_branch + root->val+ r_branch);
        int max_path = max(max(max_sum_root,l_path), r_path);
        
        return vector<int>{max_branch, max_path};
    }
    int maxPathSum(TreeNode* root) {
        vector<int> vec = max_path_sum_util(root);
        return vec[1];        
    }
};