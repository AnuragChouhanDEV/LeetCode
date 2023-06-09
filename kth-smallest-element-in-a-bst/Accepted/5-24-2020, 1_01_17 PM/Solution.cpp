// https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
    void in_order(TreeNode *root, int k, int num[]) {
        if (root == NULL)
            return;
        //cout << root->val << endl;
        in_order(root->left, k, num);
        if (++num[0] == k) {
            num[1] = root->val;
        }
        in_order(root->right, k, num);
        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int num[2] = {0};
        in_order(root, k, num);
        return num[1];
    }
};