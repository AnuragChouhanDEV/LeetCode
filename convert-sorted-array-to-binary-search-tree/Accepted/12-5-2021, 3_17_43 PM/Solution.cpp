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
public:
    TreeNode *bst_util(vector<int> &nums, int start, int end) {
        if (start > end)
            return NULL;
        int mid = (start + end)/2;
        TreeNode *new_node = new TreeNode(nums[mid]);
        if (start == end)
            return new_node;
        new_node->left = bst_util(nums, start, mid-1);
        new_node->right = bst_util(nums, mid+1, end);
        return new_node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst_util(nums, 0, nums.size()-1);
    }
};