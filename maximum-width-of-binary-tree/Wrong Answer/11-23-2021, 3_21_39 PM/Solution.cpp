// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 1;
        int result = 0;
        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
        int count = q.size();
        result = max(count, result);
        while (count--) {
            TreeNode* temp = q.front();
            q.pop();
            //if (temp->left != NULL)
            if(temp && (temp->left || temp->right)) {
                q.push(temp->left);
            //if (temp->right != NULL)
                q.push(temp->right);
            }
            }
        }
        return result;
    }
};