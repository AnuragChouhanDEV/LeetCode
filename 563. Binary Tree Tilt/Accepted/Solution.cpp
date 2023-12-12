// https://leetcode.com/problems/binary-tree-tilt/description/

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
    vector<int> res;
    int helper(TreeNode* root) {
        if (!root)
            return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        if (!root->left && !root->right)
            return root->val;
        res.push_back(abs(left-right));
        return left+right+root->val;
    }
    int findTilt(TreeNode* root) {
        if (!root) return 0;
        int lsum = helper(root->left);
        int rsum = helper(root->right);
        int ans = 0;
        for(auto it:res)
            ans+=it;
        return ans+abs(lsum-rsum);
    }
};