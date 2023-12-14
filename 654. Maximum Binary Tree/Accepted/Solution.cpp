// https://leetcode.com/problems/maximum-binary-tree/description/

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
    int get_max_idx(vector<int>& nums, int left, int right) {
        int idx = -1;
        int maxi = INT_MIN;
        for (int i = left; i <= right; ++i) {
            if (maxi < nums[i]) {
                maxi = nums[i];
                idx = i;
            }
        }
        return idx;
    }
    TreeNode* helper(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;
        int idx = get_max_idx(nums, l, r);
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = helper(nums, l, idx-1);
        root->right = helper(nums, idx+1, r);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};