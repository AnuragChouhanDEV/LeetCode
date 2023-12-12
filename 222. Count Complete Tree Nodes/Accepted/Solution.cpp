// https://leetcode.com/problems/count-complete-tree-nodes/description/

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
    int getLeftHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            root = root->left;
            height++;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftHeight = getLeftHeight(root->left);
        int rightHeight = getLeftHeight(root->right);

        if (leftHeight == rightHeight) {
            // Left subtree is a full binary tree
            return (1 << leftHeight) + countNodes(root->right);
        } else {
            // Right subtree is a full binary tree
            return (1 << rightHeight) + countNodes(root->left);
        }
    }
};