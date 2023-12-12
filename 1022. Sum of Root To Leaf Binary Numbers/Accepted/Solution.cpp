// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/

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
    int res = 0;
    void helper(TreeNode* root, int num) {
        if (!root) return;
        num = (num<<1) + root->val;
        if (!root->left && !root->right) {
            res += num;
            return;
        }
        helper(root->left, num);
        helper(root->right, num);
    }
    int sumRootToLeaf(TreeNode* root) {
        int num = 0;
        helper(root, num);
        return res;        
    }
};

/*

*/
