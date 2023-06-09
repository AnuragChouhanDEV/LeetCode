// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

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
    TreeNode* construct_bst(vector<int>& nums, int min, int max) {
        if (min > max)
            return NULL;
        int mid = min + (max - min) / 2;
        TreeNode *curr = new TreeNode(nums[mid]);
        curr->left = construct_bst(nums, min, mid - 1);
        curr->right = construct_bst(nums, mid + 1, max);
        return curr;
    } 
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return NULL;
        return construct_bst(nums, 0, nums.size() - 1);
    }
};