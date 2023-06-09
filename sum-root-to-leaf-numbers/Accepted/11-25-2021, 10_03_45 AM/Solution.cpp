// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    void find_numbers(TreeNode* root, int val, int& result) {
        int curr = val*10 + root->val;
        if(!root->left && !root->right){
            result += curr;
            return;
        }
        if(root->left) find_numbers(root->left, curr, result);
        if(root->right) find_numbers(root->right, curr, result);
    }
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int result = 0;
        find_numbers(root, 0, result);
        return result;
    }
};