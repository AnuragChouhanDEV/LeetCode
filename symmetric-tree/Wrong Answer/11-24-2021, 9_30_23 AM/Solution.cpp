// https://leetcode.com/problems/symmetric-tree

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
    void inorder(TreeNode *root, vector<int> &vec) {
        if (!root)
            return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    bool isSymmetric(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);
        int size = vec.size();
        for (int i = 0; i < size; ++i,--size) {
            if (vec[i] != vec[size-1])
                return false;
        }
        return true;
    }
};